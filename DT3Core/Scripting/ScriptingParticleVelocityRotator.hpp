#pragma once
#ifndef DT3_SCRIPTINGPARTICLEVELOCITYROTATOR
#define DT3_SCRIPTINGPARTICLEVELOCITYROTATOR
//==============================================================================
///
///	File: ScriptingParticleVelocityRotator.hpp
///
/// Copyright (C) 2000-2014 by Smells Like Donkey Software Inc. All rights reserved.
///
/// This file is subject to the terms and conditions defined in
/// file 'LICENSE.txt', which is part of this source code package.
///
//==============================================================================

#include "DT3Core/Scripting/ScriptingBase.hpp"

//==============================================================================
//==============================================================================

namespace DT3 {

//==============================================================================
/// Forward declarations
//==============================================================================

class Particles;

//==============================================================================
/// Velocity Rotator for Particle System.
//==============================================================================

class ScriptingParticleVelocityRotator: public ScriptingBase {
    public:
        DEFINE_TYPE(ScriptingParticleVelocityRotator,ScriptingBase)
        DEFINE_CREATE_AND_CLONE
        DEFINE_PLUG_NODE

                                            ScriptingParticleVelocityRotator	(void);
                                            ScriptingParticleVelocityRotator	(const ScriptingParticleVelocityRotator &rhs);
        ScriptingParticleVelocityRotator &	operator =                          (const ScriptingParticleVelocityRotator &rhs);
        virtual                             ~ScriptingParticleVelocityRotator	(void);

        virtual void                archive                 (const std::shared_ptr<Archive> &archive);

    public:
        /// Called to initialize the object
        virtual void				initialize				(void);

        /// Computes the value of the node
        /// \param plug plug to compute
        DTboolean					compute					(const PlugBase *plug);

    private:
        DTfloat						_add_angle;

        Plug<std::shared_ptr<Particles>>		_in;
        Plug<std::shared_ptr<Particles>>		_out;

};

//==============================================================================
//==============================================================================

} // DT3

#endif
