# Learning C and C++

Learning to program in C and C ++

## Description

I made simple games in C and C ++ to learn to use the commands, libraries and functions of the C and C ++ programming language.

## Description
to compile the games, go to the folder in the terminal and write gcc filename.c -o nomedese.exe (windows) or .out (linux / macOs) 

## Cloning the Repository
With Git and Node.js installed on your machine, choose location and clone repository, use this commands:

```
git https://github.com/Drete457/learning_c_and_c_plus_plus.git
cd learning_c_and_c_plus_plus
Choose a folder C or C++ then the game inside.

If you choose folder C, use this command to compile:
gcc filename.c -o gamename.exe (windows) or .out (linux / macOs)

if you choose folder C++, use this command to copile:
g++ filename.c -o gamename.exe (windows) or .out (linux / macOs) -stf=c++11
exp: g++ filename.c -o gamename.exe -stf=c++11

or in C++ you can use in your terminal:
-make (name of the cpp file) (linux) or -mingw32-make (name of the cpp file) (windows)

(don't forget to have gcc installed)

For the "HangMan Next Step project", you can use the commands above, or just use:
g++ *.cpp -o  gamename.exe (windows) or .out (linux / macOs)

If you want to make individual changes to the files 
and then add them to the game without having to compile the entire game again. 

Just run the command g++ -c *.cpp to generate all the translation units that the program will use.
Then you can join everyone translate unit by doing g++ *.o -o  gamename.exe (windows) or .out (linux / macOs)

Whenever you change a file, just make the g++ -c name of that file.cpp and join all together by doing:
g++ *.o -o  gamename.exe (windows) or .out (linux / macOs)
Compilation will be instant 

IDE
Linux - CodeLite, Website https://codelite.org
MacOs - Xcode, Apple Store
Windows - Visual Studio Community

The "HangMan using IDE" folder was made using several advanced C ++ concepts, 
we can use the previous annotations to be compiled or else one of the IDE mentioned above.
```

## Tecnologies

- GCC

## License
MIT License
