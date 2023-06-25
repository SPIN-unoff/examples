cmake_minimum_required(VERSION 3.22)
project(control_flow C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable( integer src/integer.c )
add_executable( floating_point src/floating_point.c )
add_executable( structures src/structures.c )
add_executable( unions src/unions.c )
add_executable( enum src/enum.c )
add_executable( bit_fields src/bit_fields.c )

