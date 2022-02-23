# About

Simple Tic Tac Toe game made with C++ and Raylib.

# Dependencies

* Raylib (4.0.0)
* CMake
* C++ Compiler

# Instructions

Install [CMake](https://cmake.org/download/). Make sure CMake is accessible from the system or user's PATH. 

### Generating Build System
With CMake installed run the following commands from the root of the repository (If using an older version of Raylib you may need to update the CMake cache with paths to the Library and Include directories):

~~~~
mkdir build
cd build
cmake ..
~~~~

CMake will attempt to find Raylib on the machine and if it is unsuccessful in finding the CMake script will attempt to fetch it and install it in the build directory.

### Compiling on Mac/Linux
From the build directory:
~~~~
make
~~~~

### Compiling on Windows
From the build directory open the TicTacToe.sln and select the TicTacToe project as the Startup Project. Right click to build and F5 to run.

# Platform

Windows 10 and MacOS. I couldn't get Raylib to build with CMake on Raspberry PI and I don't plan to fix it myself. When the Steam Deck releases I will try a build on Steam OS. 