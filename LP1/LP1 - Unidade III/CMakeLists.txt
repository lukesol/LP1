cmake_minimum_required(VERSION 3.18)
project (forca VERSION 1.0.0 LANGUAGES CXX )

set( GCC_COMPILE_FLAGS "-Wall" )

set( APP_NAME "forca" )

# Components
add_executable( ${APP_NAME}
    "main.cpp"
    "game.cpp")

# C++ Version
target_compile_features( ${APP_NAME}  PUBLIC cxx_std_17 )
