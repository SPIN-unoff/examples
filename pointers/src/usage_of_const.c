#include <stdio.h>
#include <float.h>

int main( int argc, char* argv[] ) {

    //**********************************************************************//

    // Imagine you have a responsible user, `Ottone Erminio`, who is keeping
    // its money in bank
    const int bank_money = 1234;
    
    // the user has a friend which is not so smart, `Ionito Enrico`, who is
    // keeping its money under the mattress
    int mattress_money = 5678; 

    // You can't steal money from `Erminio`, even if you know where he keeps his money 
    // I.E. you can't change its value even if you have a pointer
    //
    // int *bank_address = &bank_money; //error
    //
    // You can only see how much money he has (yes, a very permitting bank)
    // I.E. access to variable via `const int*` allows reading the variable
    const int *bank_address = &bank_money;

    // But you can steal money from `Enrico`
    // I.E. knowing the address you can change its value
    int *mattress_address = &mattress_money;
    
    //**********************************************************************//
    
    // Now `Erminio` lives in a house
    int house_number = 5;

    // and `Enrico` in a caravan 
    int caravan_plate = 9876;

    // Even if the house number changes due, the house will be always in the same plate
    // there fore we use a 
    int *const house_address = &house_number;
    // Doing so means that we can't move `Erminio`'s house where `Enrico` parked its caravan.
    // house_address = &caravan_plate; //error

    // But we can move `Enrico`'s caravan!
    int *caravan_address = &caravan_plate;
    // As a matter of fact we can even park `Enrico`'s caravan at `Erminio`'s house
    caravan_address = house_address; // No error (but dangerous)
    

    //**********************************************************************//
    //                          DANGER                                      //
    //**********************************************************************//

    // now a little detail on dangerous operations (casting)
    
    const int number = 5;

    //int *ptr = &number; // error, GOOD
    const int *ptr = &number; //no error, GOOD

    int *non_const_ptr = ptr; //no error, BAD (some compilers generate warnings)

    printf("number before: %d\n", number);
    *non_const_ptr = 10;
    printf("number after: %d\n", number);

    double *random_ptr = ptr; //no error, BAD (some compilers generate warnings)
                             //no error on type cast (from int to float, some compilers generate warnings)
                             //no error on type size (int has a given size, float has a bigger one
    printf("What is inside `ptr` has size %ld and has value %d\n", sizeof(*ptr), *ptr);
    printf("What is inside `random_ptr` has size %ld and has value %lf\n", sizeof(*random_ptr), *random_ptr);

    *(random_ptr) = 100.0;

    printf("After changing `random_ptr`...\n");
    printf("What is inside `ptr` has size %ld and has value %d\n", sizeof(*ptr), *ptr);
    printf("What is inside `random_ptr` has size %ld and has value %lf\n", sizeof(*random_ptr), *random_ptr);
    return 0;
}
