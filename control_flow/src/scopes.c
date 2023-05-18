#include <stdio.h>

int main( int argc, char* argv[] ) {

    int numero = 1;
    printf("numero = %d\n",numero);

    //child scope
    {
        //redefining `numero` in new scope
        int numero = 5;

        //adding a local variable in child scope
        int numero2 = 4;
        printf("numero = %d, numero2 = %d\n", numero, numero2);

        //child scope of child scope
        {
            //redefining again `numero`
            int numero = 6;
            printf("numero = %d, numero2 = %d\n", numero, numero2); //good: we can still access numero2 from 
                                                                //child scope
        }
    }
    // printf("numero = %d, numero2 = %d\n", numero, numero2); // error: numero2 is not defined in parent scope!

    printf("numero = %d\n",numero);
}
