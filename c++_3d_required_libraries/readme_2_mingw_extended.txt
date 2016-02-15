This MinGW bundle was configured for use in the Saxion C++ 3D Rendering course.
This way you know which libraries you need to configure if you decide to use a different option from the one offered here.

It contains a copy of the default MinGW bundle from this download:
http://sourceforge.net/projects/codeblocks/files/Binaries/13.12/Windows/codeblocks-13.12mingw-setup.exe

After that we overlaid this patch:
http://tehsausage.com/mingw-to-string

Then we copied the INCLUDE files for:

glm-0.9.5.4
glew-1.13.0
sfml-2.3.2

into the MinGW include folder.

Then we copied the LIB files for:

glew-1.13.0
sfml-2.3.2

into the MinGW lib folder.

In order to use dynamic linking we copied the dll files for:

glew-1.13.0
sfml-2.3.2

into the MinGW bin folder.
