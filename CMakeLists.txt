# @file CMakeLists.txt
# 
# CMake files for lambda example

cmake_minimum_required(VERSION 3.16)

# project info
project(lambda)

# C++17
set(CMAKE_CXX_STANDARD 17)

# Turn on warnings
if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # standard warnings
    add_compile_options(-Wall -Wno-unused-private-field -Wno-unused-variable)
endif()

add_executable(lambda lambda.cpp Framework.cpp)
