DEFINES += SCRIBUSVERSION=\\\"0.0\\\"
DEFINES += SCRIBUSNAME=\\\"Scribus-core\\\"

QT       += core

QT       -= gui

TARGET = scribus-core
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
        main.cpp \
    scribus.cpp

HEADERS += \
    scribus.h

OTHER_FILES += \
    README.md
