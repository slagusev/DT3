//
//  SDLWindowManager.h
//  BaseSDL
//
//  Created by Aaron Dale on 2013-10-08.
//  Copyright (c) 2013 Aaron Dale. All rights reserved.
//

#pragma once

#include "DT3Core/Platform/Common.h"

class SDLWindowManager
{
DECLARE_SINGLETON_FUNCTIONS(SDLWindowManager);
private:
    SDLWindowManager();
    ~SDLWindowManager();
public:
    bool createWindow();
    void destroyWindow();
    void clear();
    void swap();
private:
    SDL_Window* _window;
    SDL_GLContext _context;
};

