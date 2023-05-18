#include <stdio.h>
#include <stdbool.h>

int main( int argc, char* argv[] ) {
    bool flag = false;

    int a = 2;
    int b = 0;
    int c = -1;

    if( flag ) {
        printf("flag is true!\n");
    } else {
        printf("flag is false!\n");
    }

    if( !flag ) {
        printf("flag is false!\n");
    } else {
        printf("flag is true!\n");
    }

    if( flag == false ) {
        printf("flag is false!\n");
    } else {
        printf("flag is true!\n");
    }

    if( a == b ) {
        printf("a=%d and b=%d are considered equal!\n", a, b);
    } else {
        printf("a=%d and b=%d are considered different\n", a, b);
    }

    if( a ) {
        printf("a=%d is considered true\n", a);
    } else {
        printf("a=%d is considered false\n", a);
    }

    if( b ) {
        printf("b=%d is considered true\n", b);
    } else {
        printf("b=%d is considered false\n", b);
    }

    if( c ) {
        printf("c=%d is considered true\n", c);
    } else {
        printf("c=%d is considered false\n", c);
    }

    if( !c ) {
        if(a) {
            printf("c=%d is false and a=%d is true\n", c, a);
        } else {
            printf("c=%d is false and a=%d is false\n", c, a);
        }
    } else if( !b ) {
        printf("c=%d is true and b=%d is false, no info on a=%d\n", c, b, a);
    } else {
        printf("c=%d is true and b=%d is true, no info on a=%d\n", c, b, a);
    }

    return 0;
}

