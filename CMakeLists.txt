cmake_minimum_required(VERSION 3.0.0)
project(TicTacToe VERSION 0.1.0)

find_package(raylib)

add_executable(TicTacToe main.cpp)

target_sources(TicTacToe
PRIVATE
    Sprite.hpp
    Sprite.cpp
    GraphicsUtility.cpp
    GraphicsUtility.hpp
    Grid.hpp
    Grid.cpp)

target_compile_features(TicTacToe
  PRIVATE cxx_std_11)

target_link_libraries(TicTacToe raylib)

if (APPLE)
    target_link_libraries(TicTacToe "-framework CoreFoundation")
endif()

FILE(
    INSTALL
    ${CMAKE_SOURCE_DIR}/resources/
    DESTINATION resources)