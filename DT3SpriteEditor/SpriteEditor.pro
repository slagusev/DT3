######################################################################
# QT Project file
######################################################################

TEMPLATE = app
TARGET = SpriteEditor
#DEPENDPATH += . . Source ..
#INCLUDEPATH += . Source
QMAKE_CXXFLAGS+= -std=c++11 -Wunused-parameter -Wextra  \
        -fpic -fno-short-enums -fno-strict-aliasing -finline-limit=64

QMAKE_LFLAGS +=  -g -std=c++11

DEPENDPATH +=  . ../../DT3 ../DT3Core/Resources/ResourceTypes
INCLUDEPATH += . ../../DT3 ../DT3Core/Resources/ResourceTypes

INCLUDEPATH += \
    ../DT3Sprites/Types \
    ../DT3Sprites/Resources \
    ../DT3Sprites/Resources/Importers \
    ../DT3Sprites/Resources/ResourcesTypes \

INCLUDEPATH +=  . \
   ./Animation \
   ./Console \
   ./Hierarchy \
   ./Library \
   ./MeshBuilder \
   ./Performance \
   ./Properties \
   ./Resources \
   ./Scripting \
   ./Sound \
   ./Tools \
   ./World \
    ../../DT3  \
  ../DT3Core/Components \
  ../DT3Core/Devices \
  ../DT3Core/Entry \
  ../DT3Core/Objects \
  ../DT3Core/Resources/ \
  ../DT3Core/Resources/ResourceTypes \
  ../DT3Core/Resources/Importers \
  ../DT3Core/Resources/Scripting \
  ../DT3Core/Resources/System \
  ../DT3Core/Resources/Transitions \
  ../DT3Core/Types \
  ../DT3Core/Types/Animation \
  ../DT3Core/Types/Base \
  ../DT3Core/Types/FileBuffer \
  ../DT3Core/Types/Graphics \
  ../DT3Core/Types/GUI \
  ../DT3Core/Types/Math/ \
  ../DT3Core/Types/Media \
  ../DT3Core/Types/Memory \
  ../DT3Core/Types/Network \
  ../DT3Core/Types/Node \
  ../DT3Core/Types/Sound \
  ../DT3Core/Types/Text \
  ../DT3Core/Types/Threads \
  ../DT3Core/Types/Utility \
  ../DT3Core/World\
  ../DT3Core/World\


# Input
HEADERS +=  \
        EdSpriteAppMain.hpp \
        EdSpriteBitfield.hpp  \
        EdSpriteMainWindow.hpp  \
        EdSpriteEditor.hpp  \
        EdSpriteUVEditor.hpp  \
        EdSpriteTimeline.hpp  \
        EdSpriteProperties.hpp  \
        EdSpriteAnimationProperties.hpp  \
        EdSpriteJointProperties.hpp  \
        EdSpriteJointList.hpp  \
        EdSpriteLineEdit.hpp  \
        EdSpritePropertyBase.hpp  \
        EdSpriteAnimations.hpp  \
        EdSpritePropertyBoolField.hpp  \
        EdSpritePropertyDefaultField.hpp  \
        EdSpritePropertyBitfieldField.hpp  \
        EdSpriteAnimationTransferDialog.hpp  \
        EdSpriteNewEventDialog.hpp \

SOURCES += \
        EdSpriteAppMain.cpp  \
        EdSpriteBitfield.cpp  \
        EdSpriteMainWindow.cpp  \
        EdSpriteEditor.cpp  \
        EdSpriteUVEditor.cpp  \
        EdSpriteTimeline.cpp  \
        EdSpriteProperties.cpp  \
        EdSpriteAnimationProperties.cpp  \
        EdSpriteJointProperties.cpp  \
        EdSpriteJointList.cpp  \
        EdSpriteLineEdit.cpp  \
        EdSpritePropertyBase.cpp  \
        EdSpriteAnimations.cpp  \
        EdSpritePropertyBoolField.cpp  \
        EdSpritePropertyDefaultField.cpp  \
        EdSpritePropertyBitfieldField.cpp  \
        EdSpriteAnimationTransferDialog.cpp  \
        EdSpriteNewEventDialog.cpp \

RESOURCES += SpriteEditor.qrc
