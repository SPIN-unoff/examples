#include <stdio.h>
#include <stdint.h>
#include <float.h>
#include <stdbool.h>

void print_float(const float* num) {
    printf("0 x");
    for(int i = 3; i>=0; --i) {
        printf(" %.2X", *((uint8_t*)num + i));
    }
}

float build_float( int8_t sign, int8_t exp, uint32_t mantissa) {
    if(sign != 1 && sign !=0) {
        printf("error, sign must be 1(negative) or 0(positive), %d is not valid\n", sign);
        return 0;
    }
    sign <<= 7;
    uint8_t tmp[4]; 
    *((uint32_t*)tmp) = 0;
    tmp[3] = (uint8_t)sign;
    *((uint32_t*)tmp) |= (exp + 0x7F) << 24;
    *((uint32_t*)tmp) |= mantissa;
    return *((float*)tmp);
}

int main( int argc, char* argv[] ) {
    float a = 120.5;
    bool is_negative = 0;
    int16_t exponent = 0;
    uint32_t mantissa = 0;
    printf("Single precision floating point numbers occupies %ld bytes.\n", sizeof(float));

    printf("Insert number: ");
    scanf("%f", &a);
    printf("a = %f = ",a); print_float(&a); printf("\n");

    is_negative = (*((uint32_t*)&a) & 0x80 << 24) >> 31;
    printf("First bit is %d, therefore the number is %s\n\n", is_negative, is_negative ? "negative" : "positive");

    exponent = (*((uint32_t*)&a) & 0x7F80 << 16) >> 23;
    printf("The exponent is 0x%.2X = %d - 127 => %d\n\n", exponent, exponent, exponent - 127);

    mantissa = (*((uint32_t*)&a) & ~(0xFF80 << 16)) << 1;
    printf("The mantissa is 0x%.6X\n", mantissa);

    // we can also build a floating point number from its components
    float result = build_float(0,-127,1);
    printf("smallest number = %.50f = ",result); print_float(&result); printf("\n");
    return 0;
}
