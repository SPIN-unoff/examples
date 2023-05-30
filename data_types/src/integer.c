#include <stdio.h>
#include <stdint.h>


int main( int argc, char* argv[] ) {
    //signed variables
    int8_t a = 0;
    int32_t c = 0;

    //unsigned variables
    uint8_t b = 0;
    uint32_t d = 0;

    printf("The integer type `int8_t` and `uint8_t` respectively has size: %ld byte and %ld byte\n", sizeof(int8_t), sizeof(uint8_t));
    printf("\n");
    printf("The integer type `int32_t` and `uint32_t` respectively has size: %ld bytes and %ld bytes\n", sizeof(int32_t), sizeof(uint32_t));

    // The difference between signed and unsigned integers is that the MSB (Most Significant Bit)
    // is dedicated to the sign:
    //  any number whose MSB is 0, will be positive: 0x0A = 0000 1010
    //  any number whose MSB is 1, will be negative: 0x8A = 1000 1010
    //
    // For unsigned integers this will not be the case.
    // Example:
    a = 0x0A;
    b = 0x0A;
    printf("`a`=0x0A should result in a positive number: %d\n", a);
    printf("`b`=0x0A should result in a positive number: %d\n", b);

    a = 0x8A;
    b = 0x8A;
    printf("`a`=0x8A should result in a negative number: %d\n", a);
    printf("`b`=0x8A should result in a positive number: %d\n", b);

    // The biggest number we can store in an unsigned integer (8bit) is:    0xFF = 1111 1111 = 255
    // The biggest number we can store in a signed integer (8bit) is:       0x7F = 0111 1111 = 127
    // 
    // The smallest number we can store in an unsigned integer (8bit) is:   0x00 = 0000 0000 = 0
    // The smallest number we can store in a signed integer (8bit) is:      0x80 = 1000 0000 = -128
    // Example:
    printf("Max signed integer: %d, max unsigned integer: %d\n", (int8_t)0x7F, (uint8_t)0xFF);
    printf("Min signed integer: %d, min unsigned integer: %d\n", (int8_t)0x80, (uint8_t)0x00);

    // How to compute a positive integer from its binary representation?
    //  - the position of each bit represent the exponent of a power of 2: first position is power 0, second is power 1 and so on
    //  - the value of each bit represent the coefficient multiplying the aforementioned power of 2
    // Example:
    // 1011: 1*2^3 + 0*2^2 + 1*2^1 + 1*2^0 = 8 + 0 + 2 + 1 = 11
    // this is equal to the hexadecimal value `B`

    // How to compute a negative integer from its binary representation?
    //  - first compute the negate of the number: 1111 0110 -> 0000 1001
    //  - then sum 1: 1111 0110 -> 0000 1001 -> 0000 1010 = 10
    //  - therfore: 1111 0110 = 0xF6 = -10
    // Example:
    a = 0xF6;
    printf("`a`=0xF6, in decimal, is equal to %d\n", a);

    // The hexadecimal representation of a number is its representation in base 16.
    // Numbers bigger or equal than 10 in decimal base are represented with two digits,
    // in hexadecimal that is not the case, {10, 11, 12, 13, 14, 15} will be all represented
    // with one digit. Unfortunately having only 10 available digits: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} 
    // for the remaining numbers we use capital letters {A, B, C, D, E, F}
    //
    // Example:
    // 0 dec = 0x00 hex
    // 1 dec = 0x01 hex
    // 2 dec = 0x02 hex
    // 3 dec = 0x03 hex
    // 4 dec = 0x04 hex
    // 5 dec = 0x05 hex
    // 6 dec = 0x06 hex
    // 7 dec = 0x07 hex
    // 8 dec = 0x08 hex
    // 9 dec = 0x09 hex
    // 10 dec = 0x0A hex
    // 11 dec = 0x0B hex
    // 12 dec = 0x0C hex
    // 13 dec = 0x0D hex
    // 14 dec = 0x0E hex
    // 15 dec = 0x0F hex
    //
    // 16 dec = 0x10 hex

    return 0;
}
