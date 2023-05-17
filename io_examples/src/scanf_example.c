#include <stdio.h>

int main( int argc, char* argv[] ) {
    char name[32];
    int age;
    printf("What is your name? ");
    scanf("%s",name);
    // variable `name` does not require the address operator `&`
    // because of the structure of arrays, its name already represent the 
    // pointer to the first element:
    printf("Hello, %s, the first letter of your name is \'%c\'\n", name, *name);

    printf("How old are you? ");
    scanf("%d",&age);
    // variable `age` requires the address operator

    printf("Wow, %d years are a lot!\n",age);
    return 0;
}
