#include <stdio.h>
#include <stdint.h>

// It useful to 'typedef' union so that they are more easily accessible
// The following instruction is divided as such:
// [typedef (union my_union) defined_union]
//
// (union my_union) is the declaration of the union, exactly as for functions
// this means that a union must be defined later on. Obviously before using its
// elements.
//
// [typedef () defined_union] takes the argument in the middle as the sequence of keywords
// that must be redefined as a new one, in this case 'defined_union'
typedef union my_union defined_union;
void print_my_union( const defined_union *const u_ptr );

//definition of my_union
union my_union {
    float as_float;
    int as_int;
    char as_string[4];
};

int main() {
    { //usage and peculiarities
        defined_union instance;
        //all members of the union share the same memory,
        // this means that we can access them one at a time.
        // the proof of this is that all the following variables will have the same address
        printf("&instance = %p\n",&instance);
        printf("&(instance.as_float) = %p\n",&(instance.as_float));
        printf("&(instance.as_int) = %p\n",&(instance.as_int));
        printf("&(instance.as_int) = %p\n",&instance.as_string);

        //unions are used to store temporary element in
        //the same location of memory or to perform
        //implicit conversions from one type to the other
        
        // Changing one filed at a time will result in the change of all of the others
        instance.as_string[0] = 'C';
        instance.as_string[1] = 'I';
        instance.as_string[2] = 'A';
        instance.as_string[3] = 'O';
        printf("instance:\n"); print_my_union(&instance);

        instance.as_int = 1500;
        printf("instance:\n"); print_my_union(&instance);
        
        instance.as_float = 13.333323;
        printf("instance:\n"); print_my_union(&instance);
    }
    { //possible application

        //define a temporary union containing the two formats you want to represent
        // and assign a value
        // The default format will be the first one in the union
        union tmp_pack {
            double as_double;
            int64_t as_int;
        } tmp_instance = {13.3323};

        // in this case we want to see it represented in hexadecimal
        printf("%f in hexadecimal is: 0x%.8lX\n", tmp_instance.as_double, tmp_instance.as_int);

        //check passing through the cumbersome (but more controlled by the user) way
        printf("%f in hexadecimal is: 0x%.8lX\n", tmp_instance.as_double, *((int64_t*)&(tmp_instance.as_double)));

    }
    return 0;
}

void print_my_union( const defined_union *const u_ptr ) {
    printf("\t- as_int = 0x%.4X\n", u_ptr->as_int);
    printf("\t- as_float = %f\n", u_ptr->as_float);
    printf("\t- as_string = `%s`\n", u_ptr->as_string);
}
