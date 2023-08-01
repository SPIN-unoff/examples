cmake_minimum_required(VERSION 3.20)
project(files_and_memory LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_library(exe_data include/data_lib.c)
target_include_directories(exe_data PRIVATE include)

add_executable(binary_file src/binary_file.c)
target_link_libraries(binary_file PRIVATE exe_data)
target_include_directories(binary_file PRIVATE include)

add_executable(text_file src/text_file.c)
target_link_libraries(text_file PRIVATE exe_data)
target_include_directories(text_file PRIVATE include)

add_executable(malloc src/malloc.c)
add_executable(mem src/mem.c)

