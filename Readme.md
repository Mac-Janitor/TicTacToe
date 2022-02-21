# Dependencies

This program requires Raylib to run. I would suggest using vcpkg to install Raylib easily. Otherwise you will need to download raylib source and install it in order for CMake to recognize the library. I will provide better instructions at a later time. This program was made with version 4.0.0 of raylib.

# Directions

After installing Raylib run CMake as Administrator. Depending on the version of Raylib you may need to update the CMake cache with paths to the Library and Include directories. I've successfully built the app with Clang 12.0.0 and Visual Studio 2019

# Platform

Windows 10 and MacOS. I have not tried running this program on Linux though it should work.

# About

Simple Tic Tac Toe game made with C++ and Raylib.