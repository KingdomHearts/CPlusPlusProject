How to get all OpenGl libraries for codeblocks / mingw on Windows 32/64?
--------------------------------------------------------------------------

Download codeblocks / mingw
1. http://www.codeblocks.org/downloads/26
2. Download and install codeblocks-13.12mingw-setup.exe it includes the GCC compiler and GDB debugger from TDM-GCC (version 4.7.1, 32 bit)

--------------------------------------------------------------------------

Download SFML 2.3.2:
1. Choose the "GCC 4.7.1 TDM (SJLJ) - 32-bit" version
2. Check http://www.sfml-dev.org/tutorials/2.3/start-cb.php to get started so that you know how to link all the libraries

--------------------------------------------------------------------------

Now you can do 2d stuff over opengl.
To do 3d stuff over opengl we also need the OpenGL Extension Wrangler codename GLEW

Setting up GLEW

1. Download glew src zip http://glew.sourceforge.net/
2. Extract it to a folder of your choosing, you now have a structure glew-x.x.x\glew-x.x.x\*
   where * denotes auto, bin, build, config, etc
3. I renamed the nested "glew-x.x.x" to "sources" so that my structure is:
	glew-x.x.x\sources\include
4. Create glew-x.x.x\codeblocks\

Running CMAKE

1. Download CMAKE https://cmake.org/download/ eg Windows (Win32 Installer) - cmake-3.4.0-rc1-win32-x86.exe
2. Install and then run CMAKE-GUI
3. Enter <your path here>\glew-x.x.0\sources\build\cmake in "Where is the source code?"
4. Enter <your path here>\glew-x.x.0\codeblocks	in "Where to build the binaries?"
5. Click configure, codeblocks - mingw makefiles - use default native compilers
6. Click configure again, and then generate once
7. Close CMAKE

Compiling GLEW:

1. Open the generated Codeblocks project in 
\glew-x.x.0\codeblocks	
2. Build the glew_s target, you now have lib\libglew32.a, use this library to statically
   Rename libglew32.a to libglew32s.a !!! And use glew32s as the linkage id
   In addition define a GLEW_STATIC

3. Build the glew target, now you have glew32.dll and libglew32.dll.a, use this library to link dynamically (dll required)
   Link this one using glew32 (without the s)

NOTE: BUILD EITHER 2 OR 3, STATIC LINKING WONT WORK OTHERWISE

To build a project in Codeblocks with SFML static/dynamic check the SFML website.
Note openal32.dll is always needed and cannot be linked statically due to license issues.

