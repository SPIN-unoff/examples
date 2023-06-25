#include <stdio.h>
#include <stdint.h>


int main( int argc, char* argv[] ) {
    {
        enum colors_enum {
            NONE = 0x00,
            RED = 0x01,
            GREEN = 0x02,
            BLUE = 0x04
        };
        printf("enum size is %ld\n", sizeof(enum colors_enum));

        //enums are ususally used to store cases in the code that may appear, they are not meant to be modified
        // E.g.
        int8_t color = GREEN;
        switch( color ) {
            case RED:
                printf("Color is RED\n");
                break;
            case GREEN:
                printf("Color is GREEN\n");
                break;
            case BLUE:
                printf("Color is BLUE\n");
                break;
        }
    }
    {
        //Enums can also to represent settings and configuration using bitwise operations
        enum setting_enum {
            NO_SET  = 0b00000000, // 0x00 -> 0
            SET_A   = 0b00000001, // 0x01 -> 1
            SET_B   = 0b00000010, // 0x02 -> 2
            SET_C   = 0b00000100, // 0x04 -> 4
            SET_D   = 0b00001000, // 0x08 -> 8
            SET_E   = 0b00010000  // 0x10 -> 16
        };
        // note that the bitwise representation of the elements do not mix one with the other
        // Imagine you want to pass to a function the settings for A, B, and E you can do it as:
        int set_ABE = SET_A | SET_B | SET_E;
        printf("set_ABE = 0x%.2X\n", set_ABE);
        // which will become: 0x00010011 = 0x13
        //                         ^  ^^
        //                         |  ||
        //                         |  |set_A
        //                         |  |
        //                         |  set_B
        //                         |
        //                         set_E

        // Imagine now you wand to remove set_A and add SET_C
        set_ABE &= ~SET_A;
        set_ABE |= SET_C;
        printf("set_ABE = 0x%.2X\n", set_ABE);
        // which will become: 0x00010110 = 0x16
        //                         ^ ^^
        //                         | ||
        //                         | |set_B
        //                         | |
        //                         | set_C
        //                         |
        //                         set_E
        
    }

    return 0;
}
