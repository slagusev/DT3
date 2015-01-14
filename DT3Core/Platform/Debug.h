//
//  Debug.h
//  BaseSDL
//
//  Created by Aaron Dale on 2013-10-08.
//  Copyright (c) 2013 Aaron Dale. All rights reserved.
//

#pragma once

void glCheck(const char* statement, const char* filename, int line);
void glVersion();

#ifdef DEBUG

    #define GL_CHECK(statement)\
    {\
        statement;\
        glCheck(#statement, __FILE__, __LINE__);\
    }\

#else
    #define GL_CHECK(statement) statement
#endif
