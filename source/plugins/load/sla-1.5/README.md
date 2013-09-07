# Differences to Scribus

- We don't check if the file is in the correct format before reading it. In the worst case, we do a check at the end of the importing to see if some key fields have been correctly set. (the user has to tell the program, which format it was)
- We don't sanitize the values read. The document class should test its values for sanity, if this is evere needed.

# Compile

I've not sorted out, yet how to correctly link the plugin with the
project's libraries. For now, you will have to manually set the
following two values, to get the plugin to compile.

- Build directory in your project configuration
      /home/ale/docs/src/impagina-core-build/plugins/load/sla-1.5
- In the `sla-1.5.pro` make sure that `SCRIBUSLIBRARIESDIR` matches
  the place where you have copied the document image:
      SCRIBUSLIBRARIESDIR = /home/ale/docs/src/impagina-core-build/libraries

On top of it, you will have to manually copy the plugin file into the plugins directory:
    $ cp plugins/load/sla-1.5/libloadSla15.so plugins/
(you have to do it each time you recompile the plugin, or add it as a post-build action in the project)

# TODO

- Use QXMLReader and QXmlDTDHandler to check files against a DTD (it will let use improve our DTD)
- Find a way for the plugin to tell to the core which files it opens
  (how to correctly register itself in the plugins list)
