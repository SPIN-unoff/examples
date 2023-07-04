#include <stdio.h>

#define CONSTANT 2
#define SQUARE(x) x*x // this is called a macro
#define SUM(x,y) x+y
#define WRONG_SUM(x,y) x+y; // we purposefully left a trailing ';'

int main( int argc, char *argv[] ) {

    /*
     * CONSTANTS
     */
    //CONSTANT = 3; // fails because CONSTANT is not a variable
    int var = CONSTANT; // possible because var can be changed
    var = 3; // note that this statement will not change CONSTANT, it will
             // change the value stored in var

    /*
     * MACROS
     */
    printf("3 squared is %d\n", SQUARE(3));

    /*
     * SUBSTITUTION ERROR
     */
    // a defined macro IS NOT a function, it is a textual substitution
    // It means that first the compiler will re-write our code as:
    // printf("3 squared is %d\n", 3*3);

    // this will come with some disadvantages:
    printf("3+2 = %d\n", SUM(3,2)); // this works fine
    // now lets try to square the sum
    printf("(3+2)^2 is %d\n", SQUARE(SUM(3,2)) ); //this does not work
    // what did the compiler do?
    // first it substituted SUM
    // printf("(3+2)^2 is %d\n", SQUARE(3+2) );
    // then it substituted SQUARE
    // printf("(3+2)^2 is %d\n", 3+2*3+2 );

    // Now the compiler does not know what SUM and SQUARE actually means
    // so it is not able to solve ambiguous situations:
    // due to the precedence of operators 3+2*3+2 will be executed as:
    // 3+2*3+2
    // 3+6+2
    // 11

    /*
     * SUBSTITUTION ERROR
     */
    var = WRONG_SUM(4,5); // works
    var = WRONG_SUM(3,2) // works even without the ';'
    // printf("4+5 is %d\n", WRONG_SUM(4,5)); // does not work!
    // this is due to the fact that we left a ';' in the macro
    // This is not an actual error, it CAN LEAD to errors
    return 0;
}
