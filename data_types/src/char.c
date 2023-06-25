#include <stdio.h>

int main( int argc, char* argv[] ) {
    printf("size of char is: %ld\n", sizeof(char));

    //Characters are simply integers to whom it associated a representable character
    char a = 'A'; //smallest character
    printf("Char `%c` is represented as 0x%X\n", a, a);
    printf("After '%c' we have '%c'\n", a, a+1); //prints 'B'

    //string are terminated by '\0' usually implicitly but not always
    char str[5] = "CIAO";
    printf("str is: %s\n", str);

    //when working with strigs it may happen that some trailing termination
    //characters are left untouched, and they will halt the printing of the string
    char long_str[32] = "CIAO SONO\0MARCO";
    printf("long_str is: %s\n", long_str);

    //C does not support natively the string type, it is built as an array of chars
    //however in the library string.h there are powerful utilities to manage char arrays
    return 0;
}
