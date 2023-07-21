#include <stdio.h>
#include <string.h>

// By prepending an '#' in front of a macro argument, it will be treated as a string

// in this example we perform and operation an if positive we will print that operation
#define WARN_IF(x) if(x) printf("Warning \"%s\"\n", #x)

#define VALUE 10

#define STRINGIZE(x) #x
#define TO_STRING(x) STRINGIZE(x)

int main( int argc, char *argv[] ) {

    int x = 0;

    WARN_IF(VALUE==10);

    // Can we make a string from the contents of a macro?

    // Compilation fails because the expansion is executable code
    // printf("%s\n",WARN_IF(VALUE==10));

    // Logically fails because the stringification is executed before the expansion
    printf("%s\n",STRINGIZE(WARN_IF(VALUE==10)));

    // executes correctly because the expansion is executed before stringification
    printf("%s\n", TO_STRING(WARN_IF(VALUE==10)));

    // This appens as well when our macro has no arguments
    // Compilation fails because the expansion is executable code
    // printf("%s\n",VALUE);

    // Logically fails because the stringification is executed before the expansion
    printf("%s\n",STRINGIZE(VALUE));

    // executes correctly because the expansion is executed before stringification
    printf("%s\n", TO_STRING(VALUE));

    // This does not happen when dealing expression that are not macros
    // Compilation fails because the expansion is executable code
    // printf("%s\n",VALUE==10);

    // executes correctly because the stringification is executed immediately
    printf("%s\n",STRINGIZE(x==10));

    // executes correctly because there is no expansion and the stringification is executed immediately
    printf("%s\n", TO_STRING(x==10));
    return 0;
}
