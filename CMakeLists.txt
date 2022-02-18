cmake_minimum_required(VERSION 3.0.0)
project(TicTacToe VERSION 0.1.0)

find_package(raylib 3.0.0 CONFIG REQUIRED)

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
    Fotis/UI.hpp
    External/raygui/raygui.h)

target_compile_features(TicTacToe
    PRIVATE cxx_std_11)

target_link_libraries(TicTacToe PRIVATE ${raylib_LIBRARIES})
target_include_directories(TicTacToe PRIVATE ${raylib_INCLUDE_DIRS})
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