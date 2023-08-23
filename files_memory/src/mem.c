#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] ) {

    {// memset
        printf("**********\n  memset  \n**********\n");
        int name_length = sizeof(char) * 32;
    
        char *const name = (char *const)malloc(name_length);
        printf("\nname after malloc: %s", name);
    
        // since malloc does not write memory it is good practice to set
        // all the memory to a given value
        memset(name, 'A', name_length);
        printf("\nname after memset: %s", name);
        printf("\n");
        free(name);
    }

    {// memcpy vs strcpy
        printf("***********\nmemory copy\n***********\n");
        int size = sizeof(char)*5;
        char *const str1 = (char *const)malloc(size);
        char *const str2 = (char *const)malloc(size);

        //set to 0 both strings
        memset(str1, '\0', size);
        memset(str2, '\0', size);

        //copy the same string with different methods
        memcpy(str1, "AB\0CD", size);
        strcpy(str2,"AB\0CD");

        //memcpy copies the WHOLE memory allocation
        //strcpy copies up until the FIRST occurrence of '\0'
        for(int i = 0; i < size; ++i) {
            printf("str1[%d]: %c\n", i, str1[i]);
            printf("str2[%d]: %c\n", i, str2[i]);
            printf("\n");
        }

        free(str1);
        free(str2);
    }

    {// malloc vs calloc
        printf("*****************\nmemory allocation\n*****************\n");
        int size = 10;

        //malloc does not initializes the memory and allocate a single block
        int *const arr1 = (int *const)malloc(size * sizeof(int));
        //calloc initializes the memory and allocate N blocks of given size
        int *const arr2 = (int *const)calloc(size , sizeof(int));
        for(int i = 0; i < size; ++i) {
            printf("arr1[%d]: %d\n", i, arr1[i]);
            printf("arr2[%d]: %d\n", i, arr2[i]);
            printf("\n");
        }
        free(arr1);
        free(arr2);
    }
    return 0;
}
