######################################################################
# QT Project file
######################################################################

TEMPLATE = app
TARGET = LevelEditor
QT += widgets gui opengl multimedia
DEPENDPATH +=   ../../DT3 ../DT3Core/Resources/ResourceTypes
INCLUDEPATH +=  . ../../DT3 \
                  ../DT3Core/Resources/ResourceTypes \
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

QMAKE_CXXFLAGS+= -std=c++11 -fpic -fno-short-enums -fno-strict-aliasing

QMAKE_LFLAGS +=  -std=c++11
##
CONFIG(debug, debug|release){
    QMAKE_CXXFLAGS+= -Wunused-parameter -Wextra
    QMAKE_LFLAGS +=  -g
}
##
CONFIG(release, debug|release){
    QMAKE_CXXFLAGS+= -finline-limit=64
}

# Input
HEADERS += \
     $$_PRO_FILE_PWD_/EdLevelAppMain.hpp \
     $$_PRO_FILE_PWD_/EdLevelMainWindow.hpp \
     $$_PRO_FILE_PWD_/Properties/EdLevelPropertiesWindow.hpp \
     $$_PRO_FILE_PWD_/Properties/EdLevelPropertyBase.hpp  \
     $$_PRO_FILE_PWD_/Properties/EdLevelPropertyDefaultField.hpp  \
     $$_PRO_FILE_PWD_/Properties/EdLevelPropertyVector2Field.hpp \
     $$_PRO_FILE_PWD_/Properties/EdLevelPropertyVector3Field.hpp  \
     $$_PRO_FILE_PWD_/Properties/EdLevelPropertyMatrix3Field.hpp  \
     $$_PRO_FILE_PWD_/Properties/EdLevelPropertyColorField.hpp  \
     $$_PRO_FILE_PWD_/Properties/EdLevelPropertyTitleField.hpp  \
     $$_PRO_FILE_PWD_/Properties/EdLevelPropertyBoolField.hpp  \
     $$_PRO_FILE_PWD_/Properties/EdLevelPropertyEventField.hpp \
     $$_PRO_FILE_PWD_/Properties/EdLevelPropertyEnumField.hpp  \
     $$_PRO_FILE_PWD_/Properties/EdLevelPropertyRangeField.hpp \
     $$_PRO_FILE_PWD_/Properties/EdLevelColorSwatch.hpp  \
     #$$_PRO_FILE_PWD_/Game/EdLevelGame.hpp  \
     #$$_PRO_FILE_PWD_/Game/EdLevelGameGL.hpp  \
     $$_PRO_FILE_PWD_/Hierarchy/EdLevelHierarchyWindow.hpp \
     $$_PRO_FILE_PWD_/Hierarchy/EdLevelHierarchyWindowMIME.hpp  \
     $$_PRO_FILE_PWD_/Scripting/EdLevelScriptConnectionRubberBand.hpp  \
     $$_PRO_FILE_PWD_/Scripting/EdLevelScriptEventConnection.hpp  \
     $$_PRO_FILE_PWD_/Scripting/EdLevelScriptNodeStandard.hpp  \
     $$_PRO_FILE_PWD_/Scripting/EdLevelScriptPlugConnection.hpp  \
     $$_PRO_FILE_PWD_/Scripting/EdLevelScriptSelectionRubberBand.hpp  \
     $$_PRO_FILE_PWD_/Scripting/EdLevelScriptWindow.hpp  \
     $$_PRO_FILE_PWD_/Console/EdLevelConsoleWindow.hpp  \
     ##$$_PRO_FILE_PWD_/Console/ConsoleStream.hpp  \
     $$_PRO_FILE_PWD_/Performance/EdLevelPerformanceWindow.hpp  \
     $$_PRO_FILE_PWD_/Resources/EdLevelResourcesWindow.hpp  \
     $$_PRO_FILE_PWD_/Library/EdLevelLibraryWindow.hpp  \
     $$_PRO_FILE_PWD_/Library/EdLevelLibraryDialog.hpp  \
     $$_PRO_FILE_PWD_/World/EdLevelWorldWindow.hpp \
     $$_PRO_FILE_PWD_/Animation/EdLevelAnimationWindow.hpp \
     $$_PRO_FILE_PWD_/Sound/EdLevelSoundWindow.hpp  \
     $$_PRO_FILE_PWD_/Sound/EdLevelSoundBus.hpp \
     $$_PRO_FILE_PWD_/Sound/EdLevelSoundVUMeter.hpp  \
     $$_PRO_FILE_PWD_/EdLevelToolWindow.hpp  \
     $$_PRO_FILE_PWD_/Resources/EdLevelImageThumbnail.hpp  \
     $$_PRO_FILE_PWD_/Resources/EdLevelSoundThumbnail.hpp  \
     #$$_PRO_FILE_PWD_/Resources/EdLevelMaterialThumbnail.hpp   \
     $$_PRO_FILE_PWD_/Resources/EdLevelResourceImage.hpp  \
     $$_PRO_FILE_PWD_/Resources/EdLevelResourceSound.hpp  \
     #$$_PRO_FILE_PWD_/Resources/EdLevelResourceMaterial.hpp  \
     $$_PRO_FILE_PWD_/EdLevelLineEdit.hpp   \
     $$_PRO_FILE_PWD_/EdLevelLaunchDialog.hpp  \
     $$_PRO_FILE_PWD_/MeshBuilder/EdLevelMeshBuilder.hpp \
    EdLevelDocument.hpp \
    EdLevelToolEvent.hpp \
    EdLevelManipPan.hpp \
    EdLevelManipRotate.hpp \
    EdLevelManipScale.hpp \
    EdLevelTool.hpp \
    Scripting/EdLevelGroup.hpp \
    Scripting/EdLevelScriptConnection.hpp \
    World/EdLevelWorldLayout.hpp

SOURCES +=  \
    $$_PRO_FILE_PWD_/EdLevelAppMain.cpp  \
    $$_PRO_FILE_PWD_/EdLevelMainWindow.cpp  \
    $$_PRO_FILE_PWD_/Properties/EdLevelPropertiesWindow.cpp  \
    $$_PRO_FILE_PWD_/Properties/EdLevelPropertyBase.cpp  \
    $$_PRO_FILE_PWD_/Properties/EdLevelPropertyDefaultField.cpp  \
    $$_PRO_FILE_PWD_/Properties/EdLevelPropertyVector2Field.cpp  \
    $$_PRO_FILE_PWD_/Properties/EdLevelPropertyVector3Field.cpp  \
    $$_PRO_FILE_PWD_/Properties/EdLevelPropertyMatrix3Field.cpp  \
    $$_PRO_FILE_PWD_/Properties/EdLevelPropertyColorField.cpp  \
    $$_PRO_FILE_PWD_/Properties/EdLevelPropertyTitleField.cpp  \
    $$_PRO_FILE_PWD_/Properties/EdLevelPropertyBoolField.cpp  \
    $$_PRO_FILE_PWD_/Properties/EdLevelPropertyEventField.cpp  \
    $$_PRO_FILE_PWD_/Properties/EdLevelPropertyEnumField.cpp  \
    $$_PRO_FILE_PWD_/Properties/EdLevelPropertyRangeField.cpp  \
    $$_PRO_FILE_PWD_/Properties/EdLevelColorSwatch.cpp  \
    # $$_PRO_FILE_PWD_/Game/EdLevelGame.cpp  \
    #$$_PRO_FILE_PWD_/Game/EdLevelGameGL.cpp  \
    $$_PRO_FILE_PWD_/Hierarchy/EdLevelHierarchyWindow.cpp   \
    $$_PRO_FILE_PWD_/Hierarchy/EdLevelHierarchyWindowMIME.cpp  \
    $$_PRO_FILE_PWD_/Scripting/EdLevelScriptConnectionRubberBand.cpp  \
    $$_PRO_FILE_PWD_/Scripting/EdLevelScriptEventConnection.cpp  \
    $$_PRO_FILE_PWD_/Scripting/EdLevelScriptNodeStandard.cpp  \
    $$_PRO_FILE_PWD_/Scripting/EdLevelScriptPlugConnection.cpp  \
    $$_PRO_FILE_PWD_/Scripting/EdLevelScriptSelectionRubberBand.cpp  \
    $$_PRO_FILE_PWD_/Scripting/EdLevelScriptWindow.cpp  \
    $$_PRO_FILE_PWD_/Console/EdLevelConsoleWindow.cpp  \
    ##$$_PRO_FILE_PWD_/Console/ConsoleStream.cpp  \
    $$_PRO_FILE_PWD_/Performance/EdLevelPerformanceWindow.cpp  \
    $$_PRO_FILE_PWD_/Resources/EdLevelResourcesWindow.cpp  \
    $$_PRO_FILE_PWD_/Library/EdLevelLibraryWindow.cpp  \
    $$_PRO_FILE_PWD_/Library/EdLevelLibraryDialog.cpp  \
    $$_PRO_FILE_PWD_/World/EdLevelWorldWindow.cpp  \
    $$_PRO_FILE_PWD_/Animation/EdLevelAnimationWindow.cpp  \
    $$_PRO_FILE_PWD_/Sound/EdLevelSoundWindow.cpp  \
    $$_PRO_FILE_PWD_/Sound/EdLevelSoundBus.cpp  \
    $$_PRO_FILE_PWD_/Sound/EdLevelSoundVUMeter.cpp  \
    $$_PRO_FILE_PWD_/EdLevelToolWindow.cpp   \
    $$_PRO_FILE_PWD_/Resources/EdLevelImageThumbnail.cpp  \
    $$_PRO_FILE_PWD_/Resources/EdLevelSoundThumbnail.cpp  \
    #$$_PRO_FILE_PWD_/Resources/EdLevelMaterialThumbnail.cpp  \
    $$_PRO_FILE_PWD_/Resources/EdLevelResourceImage.cpp  \
    $$_PRO_FILE_PWD_/Resources/EdLevelResourceSound.cpp  \
    #$$_PRO_FILE_PWD_/Resources/EdLevelResourceMaterial.cpp  \
    $$_PRO_FILE_PWD_/EdLevelLineEdit.cpp  \
    $$_PRO_FILE_PWD_/EdLevelLaunchDialog.cpp  \
    $$_PRO_FILE_PWD_/MeshBuilder/EdLevelMeshBuilder.cpp \
    $$_PRO_FILE_PWD_/Scripting/EdLevelGroup.cpp \
    $$_PRO_FILE_PWD_/Scripting/EdLevelScriptConnection.cpp \
    EdLevelDocument.cpp \
    EdLevelToolEvent.cpp \
    EdLevelMainWindow_cmd.cpp \
    EdLevelManipPan.cpp \
    EdLevelManipRotate.cpp \
    EdLevelManipScale.cpp \
    EdLevelTool.cpp \
    World/EdLevelWorldLayout.cpp

#include the core
include($$_PRO_FILE_PWD_/../DT3Core/DT3Core.pri)

RESOURCES += $$_PRO_FILE_PWD_/LevelEditor.qrc

## LIBRARIES STUFF

QMAKE_PRE_LINK += cmake $$PWD/../DT3Core/3rdParty/ && make -j 4 V=1

INCLUDEPATH += $$PWD/../DT3Core/3rdParty/zlib-1.2.5 \
               $$PWD/../DT3Core/3rdParty/lpng151 \
               $$PWD/../DT3Core/3rdParty/md5-cc \
               $$PWD/../DT3Core/3rdParty/freetype-2.4.7/include \
               $$PWD/../DT3Core/3rdParty/libjpeg-turbo-1.3.0/libjpeg-turbo-android/include \

DEPENDPATH  += $$PWD/../DT3Core/3rdParty/zlib-1.2.5 \
               $$PWD/../DT3Core/3rdParty/lpng151 \
               $$PWD/../DT3Core/3rdParty/md5-cc \
               $$PWD/../DT3Core/3rdParty/freetype-2.4.7/include \
               $$PWD/../DT3Core/3rdParty/libjpeg-turbo-1.3.0/libjpeg-turbo-android/include \


unix:!macosx{
    LIBS+= -L$$PWD/../DT3Core/3rdParty/bin/unix
}
macosx:{
    error("no third party path set in .pro file")
}
win:{
    error("no third party path set in .pro file")
}
LIBS +=  -lfreetype -lpng -ljpeg -lzlib -ljenkins -lmd5
LIBS += -L/usr/lib/libGLEW -lGLEW



