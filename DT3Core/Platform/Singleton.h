//
//  Singleton.h
//  SkyOS
//
//  Created by Aaron Dale on 2013-09-10.
//  Copyright (c) 2013 Aaron Dale. All rights reserved.
//

#pragma once

#include <assert.h>

#define USE_DEFAULT_SINGLETON_CONSTRUCTORS(singleton)\
protected:\
singleton() { };\
virtual ~singleton() { };\


#define DECLARE_SINGLETON_FUNCTIONS(singleton)\
public:\
static singleton* createInstance();\
static singleton* getInstance();\
static void       destroyInstance();\
private:\
static singleton* _instance;\


#define DEFINE_SINGLETON_FUNCTIONS(singleton)\
singleton* singleton::_instance = nullptr;\
singleton* singleton::createInstance()\
{\
assert(_instance == nullptr && "singleton should be null before calling create");\
if(_instance == nullptr)\
{\
_instance = new singleton();\
}\
return _instance;\
}\
singleton* singleton::getInstance()\
{\
assert(_instance != nullptr && "singleton should not be null when called get");\
return _instance;\
}\
void singleton::destroyInstance()\
{\
assert(_instance != nullptr && "singleton should not be null before destroying");\
if(_instance != nullptr)\
{\
delete _instance;\
_instance = nullptr;\
}\
}\

