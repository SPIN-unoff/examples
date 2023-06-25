#include <stdio.h>
#include <stdint.h>

typedef struct bit_fields_struct bf_t;
void print_bf_t( const bf_t *const bf_ptr );

struct bit_fields_struct {
//  overall type
//  |
//  |      identifier
//  |      |
//  |      |  ':' is a separator
//  |      |   |
//  |      |   |size in BITS
//  |      |   ||
//  v      v   vv
    int8_t type:2;
    int8_t cmd:2;
    int8_t payload:4;
};

int main( int argc, char* argv[] ) {
    printf("size of bit_fields_struct = %ld\n", sizeof(bf_t));
    //This command will show that the memory occupied by bit_fields is only 1 byte
    // by summing up all the size in bits of the element of the struct we get the value `8`
    // This means that the overall size of the structure will be 8bit -> 1 byte

    bf_t instance;
    instance.type = 4; //gives warning because 4 is 0b0100 and occupies more than 2 bits;
    instance.cmd = 1;
    instance.payload = 12; //gives warning because 12 is 0b1100, since the MSB is 1, the
                           //associated number results negative, in contrast to the assigned
                           //value of 12, which is positive 
    // we should see:
    // type    =   0b00
    // cmd     =   0b01
    // payload = 0b1100
    print_bf_t(&instance);

    //the compiler chooses in which order the fields must be represented in memory
    return 0;
}

void print_bf_t( const bf_t *const bf_ptr ) {
    union tmp {
        bf_t bf;
        uint8_t as_int;
    } instance = {*bf_ptr};

    printf("\t- overall value: 0x%.1X\n", instance.as_int);
    printf("\t- type: %d\n", bf_ptr->type);
    printf("\t- cmd: %d\n", bf_ptr->cmd);
    printf("\t- payload: %d\n", bf_ptr->payload);
}
