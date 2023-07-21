#include <stdio.h>

#define G 9.81

int main( int argc, char *argv[] ) {
    float mass = 70;
#ifndef PI
#define PI 3.141
//#error undefined PI // makes the compilation stop as it's seen as an error
    printf("We forgot to define PI!\n");
#endif
#ifdef G
    printf("You weight %.2f N\n", mass * G);
#endif
#undef G
    //printf("You weight %.2f N\n", mass * G); //fails because we just deleted G as a macro
    return 0;
}
