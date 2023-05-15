#include <stdio.h>

int main( int argc, char* argv[] ) {
    char name[32];
    int age;
    printf("What is your name? ");
    scanf("%s",name);

    printf("Hello, %s, how old are you? ",name);
    scanf("%d",&age);

    printf("Wow, %d years are a lot!\n",age);
    return 0;
}
