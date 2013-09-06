QT       -= gui

TARGET = settings
TEMPLATE = lib

DEFINES += SETTINGS_LIBRARY

INCLUDEPATH  += \
    ../ \
    ../libraries

SCRIBUSLIBRARIESDIR = /home/ale/docs/src/impagina-core-build/libraries

# alternative to export LD_LIBRARY_PATH="../libraries/"
unix:QMAKE_RPATHDIR += \
    $$quote($$SCRIBUSLIBRARIESDIR)

unix:LIBS += \
    -L.. -lglobal \
    -L.. -lQtNoGui

SOURCES += settings.cpp \
    settingsRotation.cpp \
    settingsTypography.cpp \
    settingsDuplicateItem.cpp

HEADERS += \
    settings.h \
    settings_global.h \
    settingsRotation.h \
    settingsDuplicateItem.h \
    settingsTypography.h


unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
