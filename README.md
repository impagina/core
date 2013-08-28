# Scribus-Core


An experimental layout engine based on Scribus code. 


# Goals

The first and main goal of this project is:

- Create a terminal only layout engine based on Scribus code that can read .SLA files and convert them to PDF.
- It should correctly compile on Linux, Mac OS X and Windows (with MingW)

Once this goal has been achieved, some other function are already planned:

- Enable scripting based on the new Scripter engine
- Export to .EPUB
- Join multiple .SLAs into one PDF.


Join our mailing list for further discussions:  
http://lists.impagina.org/mailman/listinfo/list  
... or simply fork this repository or use the GitHub issues tracker!

# Install

For now, no binary package is available: you have to compile it.
Since it does nothing useful for now, this should not be a problem for anybody!

## Compiling with Qt Creator

If you only want have a look at the code, import a new "Git" project from `git@github.com:impagina/core.git`:

File > New File or Project > Import Project > Git Repository Clone

If you wish to contribute, you should first fork the project on https://github.com/impagina/core and then import your own for as described above.

## Compiling from the command line

Get the git repository from https://github.com/impagina/core and:
    $ qmake
    $ make
