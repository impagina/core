DEFINES += SCRIBUSVERSION=\\\"0.0\\\"
DEFINES += SCRIBUSNAME=\\\"Scribus-core\\\"

QT       += core

QT       -= gui

TARGET = scribus-core
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH  += plugins

SOURCES += \
    main.cpp \
    scribus.cpp

HEADERS += \
    scribus.h \
    plugins/pluginInterface.h

OTHER_FILES += \
    README.md
