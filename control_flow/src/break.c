#include <stdio.h>

int main( int argc, char* argv[] ) {

    int index = 0;

    printf("\nEntering for loop with index = %d\n", index);
    for( index = 0; index < 10; ++index ) {
        printf("Index in for loop: %d\n", index); 
        if(index == 5) {
            printf("Index equal to 5, exiting for in advance!\n");
            break;
        }
    }

    printf("\nResetting index to 0...\n");
    index = 0;

    printf("Entering while loop with index = %d\n", index);
    while( index < 10 ) {
        printf("Index in while loop: %d\n", index++);
        if(index == 5) {
            printf("Index equal to 5, exiting for in advance!\n");
            break;
        }
    }

    printf("\nResetting index to 0...\n");
    index = 0;

    printf("Entering do while loop with index = %d\n", index);
    do {
        printf("Index in do while loop: %d\n", index++);
        if(index == 5) {
            printf("Index equal to 5, exiting for in advance!\n");
            break;
        }
    } while( index < 10 );

    return 0;
}
