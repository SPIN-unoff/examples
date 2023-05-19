#include <stdio.h>

// look at data types
typedef enum destination {
    NONE = 0,
    HOME,
    SCHOOL,
    WORK,
    HOSPITAL
} destination_type;

int main( int argc, char* argv[] ) {

    destination_type goal = 5;

    switch( goal ) {
        case( NONE ):
            printf("You don't know where you are going!\n");
            break;
        case( HOME ):
            printf("Well, get home safe!\n");
            break;
        case( SCHOOL ):
            printf("Ask the teacher to teach you `C`!\n");
            break;
        case( WORK ):
            printf("Have a good day at work then!\n");
            break;
        case( HOSPITAL ):
            printf("This sucks! Hope you'll be fine!\n");
            break;
        default:
            printf("Well, now I do not know where you are going! What is %d?\n", goal);
            break;
    }
    return 0;
}

