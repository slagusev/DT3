//
//  Debug.cpp
//  BaseSDL
//
//  Created by Aaron Dale on 2013-10-08.
//  Copyright (c) 2013 Aaron Dale. All rights reserved.
//

#include <iostream>
#include "DT3Core/Platform/Debug.h"
#include "DT3Core/Platform/OpenGL.h"

void glCheck(const char* statement, const char* filename, int line)
{
    GLenum error = glGetError();
    if(error != GL_NO_ERROR)
    {
		std::cerr << statement << std::endl << filename << ":" << line << std::endl;
		std::cerr << "Error: " << gluErrorString(error) << std::endl;
        abort();
    }
}

void glVersion()
{
    std::cout << glGetString(GL_VERSION) << std::endl;
    std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << glGetString(GL_VENDOR) << std::endl;
    std::cout << glGetString(GL_RENDERER) << std::endl;
}
