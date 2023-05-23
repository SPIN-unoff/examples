#include <stdio.h>

int main( int argc, char* argv[] ) {

    printf("//*******************************//\n");

    int index = 0;

    while( index < 5 ) {
        printf("Index in while: %d\n", index);
        index++;
    }

    printf("Resetting index to 0\n");
    index = 0;

    do {
        printf("index in `do while`: %d\n", index);
        index++;
    } while ( index < 5 );

    printf("//*******************************//\n");

    printf("Now changing index to 10\n");
    index = 10;

    printf("//*******************************//\n");

    while( index < 5 ) {
        printf("Index in while: %d\n", index);
        index++;
    }

    printf("Resetting index to 10\n");
    index = 10;

    do {
        printf("index in `do while`: %d\n", index);
        index++;
    } while ( index < 5 );

    //*********************************************//
    //
    // In `while` constructs, the `exiting condition` 
    // is checked before executing the code in the
    // `while scope`.
    //
    // In `do while` constructs the `exiting
    // condition` is checked after executing AT LEST
    // ONCE the code in the `do while scope`. 
    //
    // However, once the exiting condition is met,
    // both will exit and stop executing the code in
    // the `scope`.
    //
    //********************************************//

    return 0;
}
