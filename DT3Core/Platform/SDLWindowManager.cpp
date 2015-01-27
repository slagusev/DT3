//
//  SDLWindowManager.cpp
//  BaseSDL
//
//  Created by Aaron Dale on 2013-10-08.
//  Copyright (c) 2013 Aaron Dale. All rights reserved.
//
#include "Singleton.h"
#include "SDLWindowManager.h"


DEFINE_SINGLETON_FUNCTIONS(SDLWindowManager);

const int RESOLUTION_X = 1280;
const int RESOLUTION_Y = 720;
const int GL_VERSION_MAJOR = 2;
const int GL_VERSION_MINOR = 3;

SDLWindowManager::SDLWindowManager()
{
    _window = nullptr;
    _context = 0;
}

SDLWindowManager::~SDLWindowManager()
{
}

bool SDLWindowManager::createWindow()
{
    SDL_InitSubSystem(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, GL_VERSION_MAJOR);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, GL_VERSION_MINOR);

    _window = SDL_CreateWindow("Base SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, RESOLUTION_X, RESOLUTION_Y, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if(_window == nullptr)
    {
        std::cerr << "Failed to create SDL window:" << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        return false;
    }

    _context = SDL_GL_CreateContext(_window);
    if(_context == nullptr)
    {
        std::cerr << "Failed to create OpenGL Context:" << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        return false;
    }

    GL_CHECK(glClearColor(1.0f, 0.0f, 0.0f, 1.0f));
    GL_CHECK(glClearDepth(1.0f));

    GL_CHECK(glEnable(GL_DEPTH_TEST));
    GL_CHECK(glDepthFunc(GL_LEQUAL));

    //GL_CHECK(glEnable(GL_CULL_FACE));
    //GL_CHECK(glCullFace(GL_BACK));

    GL_CHECK(glEnable(GL_BLEND));
    GL_CHECK(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    glVersion();

    return true;
}

void SDLWindowManager::destroyWindow()
{
    SDL_GL_DeleteContext(_context);

    SDL_DestroyWindow(_window);
    _window = nullptr;

    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void SDLWindowManager::clear()
{
    GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}


void SDLWindowManager::swap()
{
    SDL_GL_SwapWindow(_window);
}
