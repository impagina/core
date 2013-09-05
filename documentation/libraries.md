#Libraries

Currently, each set of features and each plugin are packed in libraries.

## Creating libraries

In Qt Creator, `File > New File or Project` and choose the type `Libraries > C++ Library`.  


    Introduction and Project Location

    Type:           [ Shared Library        |v]
    Name:           [ camelCaseName           ]
    Create in:      [ [...]/scribus-core      ]

                                       [ Next ]


    Kit Selection

    [x] Debug       [ [...]/scribus-core/build]
    [ ] Release:    [                         ]

                                       [ Next ]


    Select Required Modules

    [x] QtCore
    [ ] QtGui
    
                                       [ Next ]


    Class Information

    Class name:     [ CamelCaseName         |v]
    
    Header file:    [ camelCaseName.h         ]
    Source file:    [ camelCaseName.cpp       ]

                                       [ Next ]


    Project Management

    Add as a subproject:    [ ...           |v]
    Add to version control: [ git           |v]

                                     [ Finish ]


## Adding files to an existing library

    [ ] - project
        | - project.pro
        | - Headers
        | - Sources

Right click on the project name, `Add new > C++ > C++ Class`

    Enter Class Name

    Class name:     [ CamelCaseName             ]
    Base class:     [                           ]
    Type information[ None                    |v]
    
    Header file:    [ camelCaseName.h           ]
    Source file:    [ camelCaseName.cpp         ]

    Path:           [ [...]/scribus-core/library]

                                         [ Next ]

    Project Management

    Add as a project:       [ project.pro   |v]
    Add to version control: [ git           |v]

                                     [ Finish ]


In `camelCase.h` add two information from the main `.h` in you project (`project.h`:
- `#include "project_global.h"` (where `project`matches your project's name)
- `PROJECTSHARED_EXPORT` between the keyword `class` and the name of the class: `class PROJECTSHARED_EXPORT` (where `PROJECT`matches your project's name)

In the `.pro` file:

- after THE "DEFINES += ..." line:
      INCLUDEPATH  += \
      ../ \
      ../libraries
      
      # you will have to change this path to match  your setup
      SCRIBUSLIBRARIESDIR = /home/ale/docs/src/impagina-core-build/libraries

      # alternative to export LD_LIBRARY_PATH="../libraries/"
      unix:QMAKE_RPATHDIR += \
          $$quote($$SCRIBUSLIBRARIESDIR)

      unix:LIBS += \
          -L.. -lglobal \
          -L.. -lQtNoGui
 
