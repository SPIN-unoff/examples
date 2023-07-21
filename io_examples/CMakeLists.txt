cmake_minimum_required(VERSION 3.22)
project(io_example C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(printf_example src/printf_example.c)
add_executable(scanf_example src/scanf_example.c)
add_executable(cl_argument src/cl_argument.c)
