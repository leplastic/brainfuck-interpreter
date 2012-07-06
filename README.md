Brainfuck Interpreter
=====================

Just another brainfuck interpreter written in C, which supports the 8 standard operators and has virtually unlimited cells due the use of linked lists.

Installation
------------

On most Unix systems, you can directly run the 'make' to compile the brainfuck application.

    make

If you wish to install the manual, you must do it by yourself at this time. You can package the manual with

    make documentation

and then the file "branfuck.1.gz" is created. You must put it in the correct man directory, according to your distribution (usually on /usr/man or /usr/share/man).

Usage
-----

brainfuck [-f filename] [--safemode] [--help] [--input input]

Without arguments, brainfuck enters in interactive mode, expecting the code from the standard input (stdin). To stop writing code, send EOF (usually CTRL-D on Bash) and the program is interpreted.

-f allows to load some file with brainfuck code to be interpreted, instead of writing it on interactive mode.

--safemode checks for unbalanced brackets that could cause the program to create infinite loops. It's disabled by default.

--help shows the help message with explanation of each command

--input gives some default input to your program. Since , (comma) operator reads one single character at time, if you input has enough characters, it will read the first character and then move the pointer to the next one. If there are no enough characters in the given input, the , (comma) operator will ask for the next character in interactive mode.

Please refer to manual page included in 'docs' folder for more information.


License & credits
-----------------
Copyright 2011 André Silva. Some portions of this work are copyrighted by other individuals. The code is under a BSD Licence. There's no need to attribution, feel free to use the code as you wish.
