#include <stdio.h>

// It useful to 'typedef' structures so that they are more easily accessible
// The following instruction is devided as such:
// [typedef (struct my_struct) defined_struct]
//
// (struct my_struct) is the declaration of the structure, exactly as for functions
// this means that a structure must be defined later on. Obviously before using its
// elements.
//
// [typedef () defined_struct] takes the argument in the middle as the sequence of keywords
// that must be redefined as a new one, in this case 'defined_struct'
typedef struct my_struct defined_struct;
typedef struct my_second_struct defined_second_struct;

//utility functions
void print_my_struct( const defined_struct * const s_ptr );
void print_my_second_struct( const struct my_second_struct * const s_ptr ); 

//definition of my_struct
struct my_struct {
    int a;
};

//definition of my_second_struct
struct my_second_struct {
    int a;
    int b;
};

int main() {

    {
        //without using the 'typedef' keyword, structure instances must be defined as such
        //and CAN (not must) be initialized with a list of arguments between curly brackets
        struct my_struct instance = {1};

        //using the 'typedef' keyword, structure instances must be defined as such
        //and CAN (not must) be initialized with a list of arguments between curly brackets
        defined_struct instance2 = {2};

        printf("instance:\n");
        print_my_struct(&instance);

        printf("instance2:\n");
        print_my_struct(&instance2);
    }

    {
        struct my_second_struct instance = {1,2};
        defined_second_struct instance2 = {3,4};

        printf("instance:\n");
        print_my_second_struct(&instance);

        printf("instance2:\n");
        print_my_second_struct(&instance2);
    }

    return 0;
}

void print_my_struct( const defined_struct * const s_ptr ) {
    printf("\t- a = %d\n", s_ptr->a);
}

void print_my_second_struct( const struct my_second_struct * const s_ptr ) {
    printf("\t- a = %d\n", s_ptr->a);
    printf("\t- b = %d\n", s_ptr->b);
}
