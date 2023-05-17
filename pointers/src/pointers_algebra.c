#include <stdio.h>

int main( int argc, char* argv[] ) {
    int a = 0;

    int *a_ptr = &a;

    printf("a_ptr = %p\n", a_ptr);

    // adding 1 to the pointer, makes its value increment by 4!
    // This is due to the fact that an `int` occupies 4 bytes in memory,
    // and adding 1 to the pointer means going to the next `int`
    printf("a_ptr + 1 = %p\n", a_ptr + 1);

    // If we `cast` the pointer to `long int*` and only AFTER we add 1,
    // we see that the value increments by 8
    // This is due to the fact that a `long int` occupies 8 bytes in memory,
    // and adding 1 to the pointer means going to the next `long int`
    printf("(long int*)a_ptr + 1 = %p\n", (long int*)a_ptr + 1);

    // here we can see verify how much space `int` and `long int` occupy.
    printf("\nSize of int = %ld\n", sizeof(int));
    printf("Size of long int = %ld\n", sizeof(long int));
    return 0;
}
