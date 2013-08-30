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
    scribus.cpp \
    document/document.cpp

HEADERS += \
    scribus.h \
    plugins/pluginInterface.h \
    document/document.h

OTHER_FILES += \
    README.md
