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

    int numero = 3;
    printf("Type an integer from 0 to 5: ");
    scanf("%d", &numero);

    switch( numero ) {
        //forgetting the brake statement will result in unwanted behaviour
        case 0:
            printf("numero is 0\n");
        case 1:
            printf("numero is 1\n");
        case 2:
            printf("numero is between 0 e 2\n"); 
            break;
        case 5:
            printf("numero is equal to 5\n");
        default:
            printf("Don't know what to do\n");
            break;
    }
    return 0;
}

