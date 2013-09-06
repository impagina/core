The code to be integrated in Scribus-core:

- brackets (`{`) are on their own lines.
- indent have four spaces.
- camel case names (files, methods, ...).
- class names start with a uppercase, constants and macros are all caps and all other names start with a lower case
- accessors with the `get` and `set` prefix.
- no have public class variables. 
- no abreviations in the method and variable names.
- every comment has the name of the author and the date.
- every directory has a README.md file explainint its content.
- every file starts with the purpose of the file (max 10 lines).
- when needed, method should have a description.
- code snippets should not be commented, except if they work in a not natural way (hacks, ...)
- the code flow should be explained in the method description (or class description) and inline in the code.
- avoiding trivial comments for the code documentation generator (like `ObjAttrVector defaultItemAttributes; //! The default item attributes`);
