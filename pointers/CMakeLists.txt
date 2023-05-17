cmake_minimum_required(VERSION 3.22)
project(pointers C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(pointers src/pointers.c)
add_executable(usage_of_const src/usage_of_const.c)
