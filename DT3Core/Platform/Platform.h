//
//  Platform.h
//  BaseSDL
//
//  Created by Aaron Dale on 2013-10-08.
//  Copyright (c) 2013 Aaron Dale. All rights reserved.
//

#pragma once

#define LINUX 0
#define ANDROID 0
#define OSX 0
#define WINDOWS 0

// Check if we are running on OSX
#if defined __APPLE__
    #include <TargetConditionals.h>
    #if TARGET_OS_MAC // always defined, check value is not 0
        #undef OSX
        #define OSX 1
    #endif
#endif


#if defined __android__
#undef ANDROID
    #define ANDROID 1
#endif

// Check if we are running on windows
#if defined _WIN32 || defined _WIN64
    #undef WINDOWS
    #define WINDOWS 1
#endif

// Check if we are running on linux
#if defined __gnu_linux__
    #undef LINUX
    #define LINUX 1
#endif
