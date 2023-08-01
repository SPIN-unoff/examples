#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] ) {
    char *str = "Hello, world!\n\0";
    printf("%s", str);

    /* *
     * This fails because the string is considered a constant
     * *
     * strcpy(str,"hello, world!\n\0");
     * printf("%s", str);
     */

    char str1[16] = "Hello, world!\n\0";
    printf("%s", str1);

    // Ok because we initialize it as an array
    strcpy(str1,"hello, world!\n\0");
    printf("%s", str1);

    // Compiles but return an error: compiler prevent us from doing 
    // damages
    //for(int i = 16; i<100; ++i) {
    //    str1[i] = i;
    //    printf("[%d]: %s", i, str1);
    //}
    
    // Malloc syntax:
    //           cast to pointer of desired type, usually returns void
    //           |
    //           |       name of the function
    //           |       |
    //           |       |      size of the memory
    //           |       |      to be allocated: sizeof(char)*16 = 16 bytes
    //           |       |      |
    //           v       v      v
    char *str2 = (char *)malloc(sizeof(char)*16);
    printf("str2 before initialization: %s",str2);
    strcpy(str2,"Hello, world!\n\0");
    printf("str2 after initialization: %s",str2);

    //realloc is used to change size of the dynamic memory location
    str2 = (char *)realloc(str2,sizeof(char)*39);
    //realloc does not change the value inside the memory location
    printf("str2 after realloc: %s",str2);
    strcpy(str2,"Hello, world!\nThis is a single string\n\0");
    printf("str2: %s",str2);

    //mandatory when allocating memory
    free(str2);
    // free overrides the memory content, the pointer is still valid
    // but not what it points to
    printf("str2 after free: %s",str2);
    return 0;
}
