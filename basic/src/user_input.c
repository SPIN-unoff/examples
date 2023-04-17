#include <stdio.h>

int main() {
    int number = 0;

    printf("number is: %d, insert new number: ", number);
    scanf("%d",&number);
    printf("now number is: %d\n", number);
    
    printf("number is: %d, insert new number: ", number);
    scanf("%d",&number);
    printf("now number is: %d\n", number);

    return 0;
}
