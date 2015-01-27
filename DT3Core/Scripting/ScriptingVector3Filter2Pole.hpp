#pragma once
#ifndef DT3_SCRIPTINGVECTOR3FILTER2POLE
#define DT3_SCRIPTINGVECTOR3FILTER2POLE
//==============================================================================
///
///	File: ScriptingVector3Filter2Pole.hpp
///
/// Copyright (C) 2000-2014 by Smells Like Donkey Software Inc. All rights reserved.
///
/// This file is subject to the terms and conditions defined in
/// file 'LICENSE.txt', which is part of this source code package.
///
//==============================================================================

#include "DT3Core/Scripting/ScriptingBase.hpp"
#include "DT3Core/Types/Math/Filters.hpp"
#include <vector>

//==============================================================================
//==============================================================================

namespace DT3 {

//==============================================================================
/// Forward declarations
//==============================================================================

//==============================================================================
/// Simple filter for Vector types.
//==============================================================================

class ScriptingVector3Filter2Pole: public ScriptingBase {
    public:
        DEFINE_TYPE(ScriptingVector3Filter2Pole,ScriptingBase)
        DEFINE_CREATE_AND_CLONE
        DEFINE_PLUG_NODE

                                        ScriptingVector3Filter2Pole		(void);
                                        ScriptingVector3Filter2Pole		(const ScriptingVector3Filter2Pole &rhs);
        ScriptingVector3Filter2Pole&    operator =                      (const ScriptingVector3Filter2Pole &rhs);
        virtual                         ~ScriptingVector3Filter2Pole    (void);

        virtual void                    archive                 (const std::shared_ptr<Archive> &archive);

        /// Object was added to a world
        /// world world that object was added to
        virtual void                    add_to_world            (World *world);

        /// Object was removed from a world
        virtual void                    remove_from_world       (void);

    public:
        /// Registered with world to tick this node
        /// \param dt delta time
        void                            tick                    (const DTfloat dt);

        /// Called to initialize the object
        virtual void                    initialize				(void);

        /// Set the type of filter
        /// \param type filter type
        void                            set_filter_type         (const Filters::FilterType type){	_type = type;	_initialized = false;	}

        /// Get the type of filter
        /// \return filter type
        inline Filters::FilterType      filter_type             (void) 	const                   {	return _type;		}

        /// Set the number of filter passes
        /// \param num_passes number of passes
        void                            set_num_passes			(const DTint num_passes)        {	_num_passes = num_passes;	_passes.resize(num_passes);   _initialized = false;	}

        /// Get the number of filter passes
        /// \return number of passes
        inline DTint                    num_passes              (void) 	const                   {	return _num_passes;	}

        /// Set the cutoff frequency
        /// \param freq_3db cutoff frequency
        void                            set_freq3db             (const DTfloat freq_3db)        {	_freq_3db = freq_3db;	_initialized = false;	}

        /// Get the cutoff frequency
        /// \return cutoff frequency
        inline DTfloat                  freq3db                 (void) 	const                   {	return _freq_3db;	}

        /// Set frequency sampling
        /// \param freq_sampling frequency sampling
        void                            set_freq_sampling		(const DTfloat freq_sampling)   {	_freq_sampling = freq_sampling;	_initialized = false;	}

        /// Get frequency sampling
        /// \return frequency sampling
        inline DTfloat                  freq_sampling           (void) 	const                   {	return _freq_sampling;		}

    private:
        Plug<Vector3>                   _in;
        Plug<Vector3>                   _out;

        Filters::FilterType             _type;
        DTint                           _num_passes;
        DTfloat                         _freq_3db;
        DTfloat                         _freq_sampling;

        DTboolean                       _initialized;

        struct FilterBank {
            Filters _fx,_fy,_fz;
        };

        std::vector<FilterBank>         _passes;
};

//==============================================================================
//==============================================================================

} // DT3

#endif
