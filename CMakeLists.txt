cmake_minimum_required(VERSION 3.0.0)
project(TicTacToe VERSION 0.1.0)

find_package(raylib)

add_executable(TicTacToe main.cpp)

target_sources(TicTacToe
PRIVATE
    TicTacToeGrid.hpp
    TicTacToeGrid.cpp
    Fotis/Sprite.hpp
    Fotis/Sprite.cpp
    Fotis/GraphicsUtility.cpp
    Fotis/GraphicsUtility.hpp
    Fotis/Grid.hpp
    Fotis/Grid.cpp
    Fotis/Cell.hpp
    Fotis/Cell.cpp)

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