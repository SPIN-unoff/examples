cmake_minimum_required(VERSION 3.22)
project(preprocessor_example C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


add_executable( define_ex src/define.c )
add_executable( stringify_ex src/stringify.c )
add_executable( token_cat src/token_cat.c )
add_executable( header_scope src/header_scope.c )
target_include_directories( header_scope PRIVATE include )
