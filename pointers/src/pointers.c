#include <stdio.h>

struct struttura {
    int campo1;
    char campo2;
};

int main( int argc, char* argv[] ) {
    int a = 10;
    float b = 12.345;
    struct struttura istanza;
    istanza.campo1 = 55;
    istanza.campo2 = 'A';
    int z = -1;

    // usage of `&`, address operator
    printf("\nFind the address of variables\n");
    printf("a = %d, \t\t\t&a = %p\n", a, &a);
    printf("b = %f, \t\t\t&b = %p\n", b, &b);
    printf("istanza.campo1 = %d, \t\tistanza.campo2 = %c,", istanza.campo1, istanza.campo2);
    printf("\t&istanza = %p\n", &istanza);
    printf("z = %d, \t\t\t&z = %p\n", z, &z);

    int *a_ptr = &a;
    float *b_ptr = &b;
    struct struttura *istanza_ptr = &istanza;
    int *z_ptr = &z;

    // usage of `*`, dereferencing operator
    printf("\nDereferencing the address of variables\n");
    printf("*a_ptr = %d, \t\t\ta_ptr = %p\n", *a_ptr, a_ptr);
    printf("*b_ptr = %f, \t\tb_ptr = %p\n", *b_ptr, b_ptr);
    printf("istanza_ptr->campo1 = %d, \tistanza_ptr->campo2 = %c,", istanza_ptr->campo1, istanza_ptr->campo2);
    printf("istanza_ptr = %p\n", istanza_ptr);
    printf("*z_ptr = %d, \t\t\tz_ptr = %p\n", *z_ptr, z_ptr);
    return 0;
}
