cmake_minimum_required(VERSION 3.14.0)
project(TicTacToe VERSION 0.1.0)

set(CMAKE_C_STANDARD 11)

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
    Fotis/UI.cpp
    Fotis/UI.hpp)

target_compile_features(TicTacToe
    PRIVATE cxx_std_11)

find_package(raylib 4.0.0 CONFIG QUIET)

if (NOT raylib_FOUND)
    include(FetchContent)

    message("Raylib not found. Attempting to install now...")

    FetchContent_Declare(
    raylib
    URL "https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.zip"
    )

    FetchContent_GetProperties(raylib)
    FetchContent_Populate(raylib)
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})


    FetchContent_MakeAvailable(raylib)

    target_link_libraries(TicTacToe PRIVATE raylib)
    target_include_directories(TicTacToe PRIVATE raylib)  
else()
    target_link_libraries(TicTacToe PRIVATE ${raylib_LIBRARIES})
    target_include_directories(TicTacToe PRIVATE ${raylib_INCLUDE_DIRS})
endif()

if (WIN32)
    target_link_libraries(TicTacToe PRIVATE winmm)
endif()

if (APPLE)
    target_link_libraries(TicTacToe PRIVATE "-framework CoreFoundation")
endif()

target_include_directories(TicTacToe PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/external/")

# Set a symbolic link so exe can find the /resources folder
set(link_src "${CMAKE_SOURCE_DIR}/resources")
# if(UNIX AND NOT APPLE) 
if(UNIX) 
    set(link_dst "${CMAKE_CURRENT_BINARY_DIR}/resources") 
else() 
    set(link_dst "${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/resources") 
endif() 
add_custom_command( 
    TARGET TicTacToe 
    POST_BUILD COMMAND ${CMAKE_COMMAND} 
        -E create_symlink ${link_src} ${link_dst} 
    DEPENDS ${link_dst} 
    COMMENT "symbolic link ${link_src} => ${link_dst}" 
)