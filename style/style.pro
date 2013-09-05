#-------------------------------------------------
#
# Project created by QtCreator 2013-09-05T08:42:43
#
#-------------------------------------------------

QT       -= gui

TARGET = style
TEMPLATE = lib

DEFINES += STYLE_LIBRARY

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

SOURCES += style.cpp \
    styleCharacter.cpp \
    styleShape.cpp \
    styleImage.cpp \
    styleSpiral.cpp \
    stylePolygon.cpp \
    styleParagraph.cpp \
    styleLine.cpp \
    styleFill.cpp \
    styleArc.cpp \
    styleCalligraphicPen.cpp

HEADERS += style.h\
        style_global.h \
    styleCharacter.h \
    styleParagraph.h \
    styleSpiral.h \
    styleShape.h \
    stylePolygon.h \
    styleLine.h \
    styleImage.h \
    styleCalligraphicPen.h \
    styleArc.h \
    styleFill.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
