The Scribus-core code should be structured in a way that:

- It should be possible to get Qt Creator to pull the code from GitHub and run it without manual tweaking on all supported platforms (Linux, Windows and OS X for now).
- It has to be easy for the programmers -- most of all for the aspiring ones -- to find in the code what they are looking for.
- Each directory should not contain too many files and the directory tree should not be too deep.

The current structure is:

+ impagina-core/
  - impagina-core.pro
  - main.cpp
  - scribus.cpp
  - scribus.h
  + document/
    - document.cpp
    - document_global.h
    - document.h
    - document.pro
  + plugins/
    + pluginInterface.h
    + load/
      + sla-1.5/
        sla15.cpp
        sla15.h
        sla-1.5.pro
+ impagina-core-build                                      # the target for the build files
  - scribus-core*
  + libraries/                                             # contains a copy of each compiled libraries
    + document/
      - libdocument.so
  + plugins/                                               # contains a copy of each compiled plugin
    + load/                                                # contains the plugins for loading sla files
      + sla15/
        - libloadSla15.so


## Essentials

- We will use the Subdirs projects to build a structure of .pro files.
- Since we want to have plugins, we need to put the common parts of the code in libraries (data structures, ...)

## A draft

scribus-core/
  - scribus-core.pro
  + documentation/
  + libraries/                                             # the compiled libraries
  + plugins/                                               # the compiled plugins
  + source/                                                # the source code for the project
    - 
  + tests/

# Notes

Some hints:

- The Qt Creator source code (http://qt.gitorious.org/qt-creator/qt-creator/) has been mentioned as a potential good inspiraction to get a structure that is compatible with qmake.

