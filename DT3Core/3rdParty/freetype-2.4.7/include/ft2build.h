/***************************************************************************/
/*                                                                         */
/*  ft2build.h                                                             */
/*                                                                         */
/*    FreeType 2 build and setup macros.                                   */
/*    (Generic version)                                                    */
/*                                                                         */
/*  Copyright 1996-2001, 2006 by                                           */
/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
/*                                                                         */
/*  This file is part of the FreeType project, and may only be used,       */
/*  modified, and distributed under the terms of the FreeType project      */
/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
/*  this file you indicate that you have read the license and              */
/*  understand and accept it fully.                                        */
/*                                                                         */
/***************************************************************************/


  /*************************************************************************/
  /*                                                                       */
  /* This file corresponds to the default `ft2build.h' file for            */
  /* FreeType 2.  It uses the `freetype' include root.                     */
  /*                                                                       */
  /* Note that specific platforms might use a different configuration.     */
  /* See builds/unix/ft2unix.h for an example.                             */
  /*                                                                       */
  /*************************************************************************/


#ifndef __FT2_BUILD_GENERIC_H__
#define __FT2_BUILD_GENERIC_H__

#define FT_INTERNAL_OBJECTS_H             <freetype/internal/ftobjs.h>
#define FT_INTERNAL_PIC_H                 <freetype/internal/ftpic.h>
#define FT_INTERNAL_STREAM_H              <freetype/internal/ftstream.h>
#define FT_INTERNAL_MEMORY_H              <freetype/internal/ftmemory.h>
#define FT_INTERNAL_DEBUG_H               <freetype/internal/ftdebug.h>
#define FT_INTERNAL_CALC_H                <freetype/internal/ftcalc.h>
#define FT_INTERNAL_DRIVER_H              <freetype/internal/ftdriver.h>
#define FT_INTERNAL_TRACE_H               <freetype/internal/fttrace.h>
#define FT_INTERNAL_GLYPH_LOADER_H        <freetype/internal/ftgloadr.h>
#define FT_INTERNAL_SFNT_H                <freetype/internal/sfnt.h>
#define FT_INTERNAL_SERVICE_H             <freetype/internal/ftserv.h>
#define FT_INTERNAL_RFORK_H               <freetype/internal/ftrfork.h>
#define FT_INTERNAL_VALIDATE_H            <freetype/internal/ftvalid.h>

#define FT_INTERNAL_TRUETYPE_TYPES_H      <freetype/internal/tttypes.h>
#define FT_INTERNAL_TYPE1_TYPES_H         <freetype/internal/t1types.h>

#define FT_INTERNAL_POSTSCRIPT_AUX_H      <freetype/internal/psaux.h>
#define FT_INTERNAL_POSTSCRIPT_HINTS_H    <freetype/internal/pshints.h>
#define FT_INTERNAL_POSTSCRIPT_GLOBALS_H  <freetype/internal/psglobal.h>

#define FT_INTERNAL_AUTOHINT_H            <freetype/internal/autohint.h>


#include <freetype/config/ftheader.h>

#endif /* __FT2_BUILD_GENERIC_H__ */


/* END */
