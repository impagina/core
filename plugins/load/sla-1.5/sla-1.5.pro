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

TARGET = loadSla15


SOURCES += \
    sla15.cpp
HEADERS += \
    sla15.h
OTHER_FILES += \
    README.md
