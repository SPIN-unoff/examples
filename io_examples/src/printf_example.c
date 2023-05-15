#include <stdio.h>

int main( int argc, char* argv[] ) {
    
    printf("Hello, world!\n");

    // Building a string using double quotes will output the variable intuitively
    char name[] = "Pippo";
    printf("Hello, %s!\n",name);

    // Single quotes don't work in initializing a string
    // single quotes are used to represent a single character
    //char name2[] = 'Topolino'; // TODO: comment it out

    // It is still possible to build a string as an ARRAY of characters
    char name3[] = {'P', 'l', 'u', 't', 'o'};
    printf("Hello, %s!\n",name3);

    // A string built by appending characters needs to be TERMINATED
    char name4[] = {'M', 'i', 'n', 'n', 'i', 'e', '\0'};
    printf("Hello, %s!\n",name4);

    /*******************************************************
     * NOTE: `string` is not a native type in C. It is
     * implemented as an ARRAY of CHARACTERS, terminated with 
     * a special string-termination CHARACTER: '\0'.
     *
     * Even `name` has it, although we can not see it from its
     * construction.
     */

    if( name[5] == '\0') printf("%s has termination character\n",name);
    else printf("%s has no termination character\n",name);

    if( name3[5] == '\0') printf("%s has termination character\n",name3);
    else printf("%s has no termination character\n",name3);

    if( name4[6] == '\0') printf("%s has termination character\n",name4);
    else printf("%s has no termination character\n",name3);

    return 0;
}
