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
    Fotis/Cell.cpp
    External/raygui/raygui.h)

target_compile_features(TicTacToe
  PRIVATE cxx_std_11)

target_link_libraries(TicTacToe PRIVATE raylib)


if (APPLE)
    target_link_libraries(TicTacToe PRIVATE "-framework CoreFoundation")
endif()

target_include_directories(TicTacToe PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/external/")

FILE(
    INSTALL
    ${CMAKE_SOURCE_DIR}/resources/
    DESTINATION resources)