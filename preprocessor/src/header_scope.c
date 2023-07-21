#include <stdio.h>

// include directive used with `"` means that the compiler will look
// among the user defined files first (also in the current directory) and only after
// among the system defined directories
#include "header_scope.h"

// include directive used with `<>` means that the compiler will use a
// list of possible paths under which it will look for header files.
// This directive does not gives an error because in the CMakeLists.txt we
// added the line:
//
// target_include_directories( header_scope PRIVATE include )
//
// this associate to the target `header_scope`, our binary, the directory `include` as
// one of system defined directories
#include <example_lib.h>

// This one fails because it was not possible to find such a header file 
// among the system directories because we never added the current path to that list
//#include <header_scope.h>

// This one does not fails because a path to `example_lib.h` exists among the system 
// defined directories
// #include "example_lib.h"

int main( int argc, char *argv[] ) {
    my_function1();
    my_function2();
    return 0;
}

void my_function1() {
    printf("MY FUNCTION 1\n");
}

void my_function2() {
    printf("MY FUNCTION 2\n");
}
