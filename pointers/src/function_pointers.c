#include <stdio.h>
#include <stdbool.h>

typedef struct obj obj_t;
typedef obj_t * const obj_ptr;
typedef void (*act_fptr)(const obj_ptr, int);
typedef const obj_ptr (*check_fptr)(const obj_ptr, char);
typedef obj_ptr (*mod_fptr)(obj_ptr, int);

struct obj {
    int pin;
    char type;
    const int code;
    act_fptr doit;
};

void servo_act( const obj_ptr self, int ref ) {
    if(self != NULL) {
        printf("Actuating servo `%c` at pin=%d with pwm=%d\n", self->type, self->pin, ref);
    }
}

void other_act( const obj_ptr self, int ref ) {
    if(self != NULL) {
        printf("Actuating `%c` motor at pin=%d with input=%d\n", self->type, self->pin, ref);
    }
}

const obj_ptr type_check( const obj_ptr self, char ref ) {
    if(self->type == ref) {
        printf("Check for type is true, actuating on pin=%d\n", self->pin);
        return self;
    } else {
        printf("Check for type failed! Interrupting actuation on pin=%d\n", self->pin);
        return NULL;
    }
}

const obj_ptr improper_check( const obj_ptr self, char code ) {
    if(self->code == code) {
        printf("Check for code is true, actuating on pin=%d\n", self->pin);
        return self;
    } else {
        printf("Check for code failed! Interrupting actuation on pin=%d\n", self->pin);
        return NULL;
    }
}

obj_ptr change_pin( obj_ptr self, int new_pin) {
    self->pin = new_pin;
    return self;
}

int main( int argc, char* argv[] ) {
    
    obj_t obj_array[6] = {
        {0, 'A', 0xFA, servo_act},
        {1, 'B', 0xFB, other_act},
        {2, 'C', 0x0A, other_act},
        {3, 'D', 0x03, servo_act},
        {4, 'E', 0x32, other_act},
        {5, 'F', 0x41, servo_act},
    };

    printf("\n");
    printf("\n************* CRUDE *************\n");
    for( int i = 0; i < 6; ++i ) {
        obj_array[i].doit( obj_array + i, i);
    }

    printf("\n************* TYPE CHECK *************\n");
    for( int i = 0; i < 6; ++i ) {
        obj_array[i].doit( type_check(obj_array + i, 'C'), i);
    }

    printf("\n************* IMPROPER CHECK *************\n");
    for( int i = 0; i < 6; ++i ) {
        obj_array[i].doit( improper_check(obj_array + i, 0x32), i);
    }

    printf("\n************* CHANGE PIN *************\n");
    for( int i = 0; i < 6; ++i ) {
        obj_array[i].doit( change_pin(obj_array + i, 10), i);
    }

    printf("\n************* TYPE CHECK AND CHANGE *************\n");
    for( int i = 0; i < 6; ++i ) {
        obj_array[i].doit( type_check( change_pin(obj_array + i, 10), 'C'), i);
    }


    // Fails due to ordering of functions
    //printf("\n************* CHANGE AND TYPE CHECK *************\n");
    //for( int i = 0; i < 6; ++i ) {
    //    obj_array[i].doit( change_pin( type_check( obj_array + i, 'C'), 10), i);
    //}
    return 0;
}
