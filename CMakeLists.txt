cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)

project(LearnOpenGL)

add_definitions(-DGL_SILENCE_DEPRECATION)

add_subdirectory(glad)

add_subdirectory(1_1)
add_subdirectory(1_2)
