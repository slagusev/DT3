set(CMAKE_VERBOSE_MAKEFILE on)
cmake_minimum_required(VERSION 2.8)
# First scratch project for linux using sdl as windowing system.

PROJECT(GAME C CXX)

#SET VARIABLES
enable_language(ASM)
set(CMAKE_C_COMPILER_INIT g++)
#set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}   -D_REENTRANT -pthread -Wl,--no-whole-archive -fno-short-enums -fno-strict-aliasing  -g " )
#set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS}   -pthread -Wall " )
#set( CMAKE_ASM_FLAGS "${CMAKE_C_FLAGS}" )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g " )
#set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_C_FLAGS}" )
#set( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_C_FLAGS}" )
#set( CMAKE_MODULE_LINKER_FLAGS "${CMAKE_C_FLAGS}" )


set(ENGINE_ROOT "${PROJECT_SOURCE_DIR}/../DT3Core/")
set(GAME_SRC_DIR "${PROJECT_SOURCE_DIR}/src_game/")
set(GAME_NAME "Game")

####In case the engine would like to be handle like a library###
option(ENGINE_AS_LIBRARY "ASD" TRUE)

### In case of compiling the SDL system.
option(USE_SDL2 "ASD" TRUE) 

### --------------DEFAULT VARIABLES-------------------- ###
### Usefull for configuring diferent OS targets
##3 /bin/{mac,ios,android,windows,other}
set(DEFAULT_THIRD_PARTY_PATH "${ENGINE_ROOT}/bin/unix")


### When compiling as a library, we might want to have it go somewhere else.
set(DEFAULT_DT3CORE_PATH "${ENGINE_ROOT}/bin/unix")


### 3rd party Core Libraries location 			     ###
### Will be evaluated in the DT3Core/3rdParty/CMakeFiles.txt ###
set(THIRD_PARTY_OUTPUT_LIBRARY_PATH ${DEFAULT_THIRD_PARTY_PATH})

### DT3Core location 				             ###
### Only used when compiling as a library. 		     ###
### Will be evaluated in the DT3Core/3rdParty/CMakeFiles.txt ###
if(ENGINE_AS_LIBRARY)
set(DT3_CORE_OUTPUT_PATH ${DEFAULT_DT3CORE_PATH})
endif(ENGINE_AS_LIBRARY)

##validate if library is present
if(USE_SDL2)
	if(NOT EXISTS "${ENGINE_ROOT}/3rdParty/SDL2/")
	option(USE_SDL2 OFF)
#	set(AB_PATH "")
	get_filename_component(AB_PATH "${ENGINE_ROOT}/3rdParty/" REALPATH)
	message(WARNING "trying to use SDL2, but library not present at 3rdParty folder See: " "${AB_PATH}/" "README for more information.")
	endif(NOT EXISTS "${ENGINE_ROOT}/3rdParty/SDL2/")	
endif(USE_SDL2)	

##### Find needed packages #####
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

### BUILD IF NOT LIBRARY, OTHERWISE THE DT3Core will take of building them.
if (NOT ENGINE_AS_LIBRARY)
add_subdirectory("${ENGINE_ROOT}/3rdParty/" ${THIRD_PARTY_OUTPUT_LIBRARY_PATH})
endif (NOT ENGINE_AS_LIBRARY)

include_directories(${GAME_SRC_DIR})
include_directories(${ENGINE_ROOT})
include_directories(${ENGINE_ROOT}/../)

# Library includes

#set(ENGINE_INCLUDES "")
include_directories(${ENGINE_INCLUDES})
include_directories("${ENGINE_ROOT}/3rdParty/zlib-1.2.5")
include_directories("${ENGINE_ROOT}/3rdParty/")
include_directories("${ENGINE_ROOT}/3rdParty/freetype-2.4.7/include")
include_directories("${ENGINE_ROOT}/3rdParty/lpng151")
include_directories("${ENGINE_ROOT}/3rdParty/md5-cc")

link_directories("${ENGINE_ROOT}/bin/unix")
link_directories("${OPENGL_gl_LIBRARY}")
link_directories("${ENGINE_ROOT}/3rdParty/")

set(MODULE_LIBS ${MODULE_LIBS} "stdc++"  "GLEW" "GL" "GLU" "X11" "rt" "m" "pthread" "dl" "freetype" "zlib" "png" "md5" "jenkins" "jpeg" )
add_definitions("-lstdc++" "--std=c++11" ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} "-ldl" "-lm" "-lpthread"  "-lGLEW" "-lX11" "-lrt"   "-lfreetype" "-lzlib" "-lpng" "-lmd5" "-ljenkins" "-ljpeg" )


#### SDL2 Optionals
if(USE_SDL2 AND NOT ENGINE_AS_LIBRARY)
	message("USING SDL2@@@@!!!!")
	set(MODULE_LIBS  ${MODULE_LIBS} "SDL2main" "SDL2" )
	add_definitions("-lSDL2main" "-lSDL2" )
	include_directories("${ENGINE_ROOT}/3rdParty/SDL2/include")
##needs tweaking, cause not all platform code belongs to SDL2....
	file(GLOB_RECURSE PROJECT_SRCS 
                "${ENGINE_ROOT}/Platform/*.cpp"
                "${ENGINE_ROOT}/Platform/*.h"
          ) 
         SET(GAME_SOURCES ${GAME_SOURCES} ${PROJECT_SRCS})
elseif(USE_SDL2 AND  ENGINE_AS_LIBRARY)
	set(MODULE_LIBS  ${MODULE_LIBS} "SDL2main" "SDL2" )
	add_definitions("-lSDL2main" "-lSDL2" )
	include_directories("${ENGINE_ROOT}/3rdParty/SDL2/include")
endif(USE_SDL2 AND NOT  ENGINE_AS_LIBRARY)


SET(GAME_SOURCES )
#build as library
if ( ENGINE_AS_LIBRARY)
set(MODULE_LIBS ${MODULE_LIBS}  "DT3Core")
add_definitions("-lDT3Core")
##TODO:ADD the DT3Core subdirectory
#add_subdirectory("${ENGINE_ROOT}/" ${CMAKE_BINARY_DIR})
add_subdirectory("${ENGINE_ROOT}/" "${ENGINE_ROOT}/build")

else()
message("Not as a library")
#	TODO: only linux hal?.. sad.
    	file(GLOB_RECURSE PROJECT_SRCS
            "${ENGINE_ROOT}/../DT3Linux/HAL.hpp"
            "${ENGINE_ROOT}/../DT3Linux/HAL.cpp"
   	 )
        SET(GAME_SOURCES ${GAME_SOURCES} ${PROJECT_SRCS})

	file(GLOB_RECURSE PROJECT_SRCS
                "${ENGINE_ROOT}/Components/*"
                "${ENGINE_ROOT}/Devices/*"
                "${ENGINE_ROOT}/Entry/*"
                "${ENGINE_ROOT}/Objects/*"
                "${ENGINE_ROOT}/Resources/*"
                "${ENGINE_ROOT}/Scripting/*"
                "${ENGINE_ROOT}/System/*"
                "${ENGINE_ROOT}/Tools/*"
                "${ENGINE_ROOT}/Transitions/*"
                "${ENGINE_ROOT}/Types/*.hpp"
                "${ENGINE_ROOT}/Types/*.cpp"
                "${ENGINE_ROOT}/Types/Utility/ContextSwitcher_asm.S"
                "${ENGINE_ROOT}/World/*"
        ) 
        SET(GAME_SOURCES ${GAME_SOURCES} ${PROJECT_SRCS})
	file(GLOB_RECURSE PROJECT_SRCS
                "${ENGINE_ROOT}/../DT3OpenGL/*.hpp"
                "${ENGINE_ROOT}/../DT3OpenGL/*.cpp"
        )
        SET(GAME_SOURCES ${GAME_SOURCES} ${PROJECT_SRCS})

endif(ENGINE_AS_LIBRARY)


set(GAME_SOURCES ${GAME_SOURCES} "${GAME_SRC_DIR}/main.cpp")
#	set(GAME_SOURCES ${GAME_SOURCES} "main.cpp")

add_executable(${GAME_NAME} WIN32 ${GAME_SOURCES})

target_link_libraries(${GAME_NAME} ${MODULE_LIBS} )

set_target_properties(${GAME_NAME} PROPERTIES
    OUTPUT_NAME "${GAME_NAME}" )



















