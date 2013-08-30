# DEFINES += SCRIBUSPLUGINVERSION=\\\"0.0\\\"
DEFINES += "SCRIBUSPLUGINNAME=\\\"sla15_loader\\\""

TEMPLATE = lib

QT       -= gui

CONFIG   += console
CONFIG   += plugin
CONFIG   -= app_bundle
# DESTDIR += ../plugins
CONFIG   += debug

INCLUDEPATH  += ../../..

# SCRIBUSLIBRARIESDIR = ../libraries
#SCRIBUSLIBRARIESDIR = $$OUT_PWD/../../../libraries
SCRIBUSLIBRARIESDIR = /home/ale/docs/src/impagina-core-build/libraries

# alternative to export LD_LIBRARY_PATH="../libraries/"
unix:QMAKE_RPATHDIR += \
    $$quote($$SCRIBUSLIBRARIESDIR)
    #../../../libraries
unix:LIBS += \
    -L../../../libraries -ldocument

TARGET = loadSla15


SOURCES += \
    sla15.cpp
HEADERS += \
    sla15.h
OTHER_FILES += \
    README.md
