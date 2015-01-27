//==============================================================================
///
///	File: FileHandleCompressedFD.cpp
///
/// Copyright (C) 2000-2014 by Smells Like Donkey Software Inc. All rights reserved.
///
/// This file is subject to the terms and conditions defined in
/// file 'LICENSE.txt', which is part of this source code package.
///
//==============================================================================

#include "DT3Core/Types/FileBuffer/FileHandleCompressedFD.hpp"
#include "DT3Core/Types/FileBuffer/FilePath.hpp"
#include "DT3Core/Types/Math/MoreMath.hpp"
#include "DT3Core/Types/Utility/Assert.hpp"
#include "DT3Core/Types/Utility/Error.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

extern "C" {
    #include "zlib.h"
}

//==============================================================================
//==============================================================================

namespace DT3 {

//==============================================================================
/// Standard class constructors/destructors
//==============================================================================

FileHandleCompressedFD::FileHandleCompressedFD (void)
{

}

FileHandleCompressedFD::~FileHandleCompressedFD (void)
{

}

//==============================================================================
//==============================================================================

DTsize FileHandleCompressedFD::read (DTubyte *buffer, DTsize size)
{
    if (_file_g >= static_cast<DTsize>(_data.size()))
        _eof = true;

    DTsize gcount = MoreMath::min( (DTsize) size, (DTsize) (_data.size() - _file_g) );

    // We aren't actually reading from a file, we're reading from the decompressed buffer
    ::memcpy(buffer, &_data[_file_g], (size_t) gcount);

    _file_g += size;

    return gcount;
}

void FileHandleCompressedFD::write (const DTubyte *buffer, DTsize size)
{
    ERRORMSG("This function is unsupported");
}

//==============================================================================
//==============================================================================

DTerr FileHandleCompressedFD::open_file (const FilePath &pathname, DTsize start, DTsize length, DTsize uncompressed_length)
{
    DTint fd;

    fd = ::open(pathname.full_path().c_str(), O_RDONLY);
    if (fd < 0) {
        return DT3_ERR_FILE_OPEN_FAILED;
    }

    _eof = false;
    _file_g = 0;

    set_fd(fd,start,length,uncompressed_length);

    return DT3_ERR_NONE;
}

DTerr FileHandleCompressedFD::set_fd (DTint fd, DTsize start, DTsize length, DTsize uncompressed_length)
{
    std::vector<DTubyte>  compressed_buffer;

    // Read the compressed file
    compressed_buffer.resize(length);

    // Read the compressed data from wherever it is in the file
    ::lseek(fd, start, SEEK_SET);
    ::read( fd, (char*) &compressed_buffer[0], (size_t) compressed_buffer.size());

    // Uncompress the data
    _data.resize(uncompressed_length);

    // Use zlib to compress the buffer
    z_stream strm;
    strm.zalloc = 0;
    strm.zfree = 0;
    strm.next_in = reinterpret_cast<DTubyte *>(&compressed_buffer[0]);
    strm.avail_in = (uInt) compressed_buffer.size();
    strm.next_out = reinterpret_cast<DTubyte *>(&_data[0]);
    strm.avail_out = (uInt) _data.size();

    inflateInit(&strm);

    DTint err;

    while (strm.total_out < _data.size() && strm.total_in < compressed_buffer.size()) {
        err = inflate(&strm, Z_NO_FLUSH);
        ASSERT(err >= 0);
        if (err == Z_STREAM_END)
            break;
    }

    inflateEnd(&strm);

    ::close(fd);

    return DT3_ERR_NONE;
}

void FileHandleCompressedFD::close (void)
{
    // Should already be closed
}

void FileHandleCompressedFD::seek_p (DToffset p, Relative r)
{
    ASSERT(0);  // unsupported
}

void FileHandleCompressedFD::seek_g (DToffset g, Relative r)
{
    switch (r) {
        case FROM_CURRENT:		_file_g += g;                   break;
        case FROM_BEGINNING:	_file_g = g;                    break;
        case FROM_END:			_file_g = _data.size() - g;		break;
    };

//	// update Progress
//	if (cache->_progress) {
//		cache->_progress->update(_file_g, _data.size());
//		cache->_last_update = 0;
//	}

}

//==============================================================================
//==============================================================================

} // DT3
