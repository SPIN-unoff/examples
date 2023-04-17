#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t length = 0;
    uint32_t height = 0;

    printf("Insert rectangle length: ");
    scanf("%d",&length);

    printf("Insert rectangle height: ");
    scanf("%d",&height);

    uint32_t area = length * height;
    uint32_t perimeter = 2 * ( length + height);

    printf("\nRectangle results:\n");
    printf("\tArea = %d\n", area);
    printf("\tPerimeter = %d\n", perimeter);
    return 0;
}
