#include <stdio.h>

int multiply( int a, int b );
int my_printf( char a, int b);

int main( int argc, char* argv[] ) {
    int a = 4;
    int b = 2;

    printf("Insert a: ");
    scanf("%d", &a);

    printf("Insert b: ");
    scanf("%d", &b);

    printf("Multiplying %d and %d\n", a, b);
    printf("Product = ");
    int product = multiply(a,b);
    printf(" = %d\n", product);

    //*********************************************//

    my_printf('*',9);
    return 0;
}

int multiply( int a, int b ) {
    if( a == 0 || b == 0 ) {
        return 0;
    }
    else if( b == 1 ) {
        printf("%d", a);
        return a;
    } 
    else {
        printf("%d + ", a);
        return a + multiply( a, b-1 );
    } 
}

int my_printf( char a, int b ) {
    if( b == 0 ) {
        printf("\n");
        return 0;
    } else {
        printf("%c", a);
        return my_printf(a,b-1);
    }
}
