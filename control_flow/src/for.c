#include <stdio.h>

int main( int argc, char* argv[] ) {
    int index = 0;

    printf("index before entering the loop: %d\n", index);

    for(index = 0; index < 5; ++index) {
        printf("index: %d\n", index);
    }

    printf("index at the end of the loop: %d\n", index);
    return 0;
}
