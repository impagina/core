#-------------------------------------------------
#
# Project created by QtCreator 2013-09-03T09:23:22
#
#-------------------------------------------------

QT       -= gui

TARGET = global
TEMPLATE = lib

DEFINES += GLOBAL_LIBRARY

SOURCES += global.cpp

HEADERS += global.h\
        global_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
