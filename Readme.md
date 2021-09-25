# Dependencies

This program requires Raylib to run. I would suggest using vcpkg to install Raylib easily. Otherwise you will need to download raylib source and install it in order for CMake to recognize the library. I will provide better instructions at a later time. I have been using Version 3.0 of Raylib because there was an unresolved defect that caused problems on Mac.

# Directions

After installing Raylib run CMake as Administrator. Depending on the version of Raylib you may need to update the CMake cache with paths to the Library and Include directories. I've successfully built the app with Clang 12.0.0 and Visual Studio 2019

# Platform

Windows 10 and MacOS. I have not tried running this program on Linux though it should work.

# About

Simple Tic Tac Toe game made with C++ and Raylib. Font loading is incredibly unoptimized at the moment and will cause the program to hang when it starts. I will be updating the font to use Signed Distanced Fields to resolve this problem.