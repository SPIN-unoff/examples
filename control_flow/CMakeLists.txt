cmake_minimum_required(VERSION 3.22)
project(control_flow C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable( if_else src/if_else.c )
add_executable( for src/for.c )
add_executable( scopes src/scopes.c )
