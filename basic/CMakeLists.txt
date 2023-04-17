cmake_minimum_required(VERSION 3.22)
project(basics C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(hello_world src/hello_world.c)
add_executable(overflow src/overflow.c)
add_executable(user_input src/user_input.c)
add_executable(rectangle_calculator src/rectangle_calculator.c)
add_executable(fix_me src/fix_me.c)
