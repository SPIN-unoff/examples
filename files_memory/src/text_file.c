#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <data_lib.h>

int main( int argc, char *argv[] ) {
    FILE *fptr;
    /**
     * Writing
     */

    fptr = fopen("./cache/text_file.txt", "w");

    // if the file could not be opened the result will be NULL
    // NULL is a defined macro used to initialize a pointer pointing
    // to nothing
    if(fptr != NULL) {
        printf("File has been successfully opened!\n");
    } else {
        // It is good practice to redirect errors on the `stderr` stream
        fprintf(stderr,"Error opening file!\n");
        return 1;
    }

    // array population
    const int company_size = 5;
    struct employee company[company_size];
    company[0]._id = 0;
    company[0]._hourly_rate = 1000;
    company[0]._role = CEO;
    for(int i = 1; i < company_size; ++i) {
        company[i]._id = i + 10;
        company[i]._hourly_rate = 10*i;
        company[i]._role = 1 + (i/2) % 2;
    }
    // Print data before writing
    printf("\nData written to file\n");
    for(int i = 0; i < company_size; ++i) {
        employee_printf(stdout,company+i);
        fprintf(fptr,"%d %d %s\n", company[i]._id, company[i]._hourly_rate, role_names[company[i]._role]);
    }
    // write the whole array in a file in binary format
    fclose(fptr);

    /**
     * Reading
     */

    fptr = fopen("./cache/text_file.txt", "r");

    // if the file could not be opened the result will be NULL
    // NULL is a defined macro used to initialize a pointer pointing
    // to nothing
    if(fptr != NULL) {
        printf("File has been successfully opened!\n");
    } else {
        // It is good practice to redirect errors on the `stderr` stream
        fprintf(stderr,"Error opening file!\n");
        return 1;
    }
    
    // prepare memory to read in the file
    struct employee read_company[company_size];
    // read from file
    {
        char name[20];
        for(int i = 0; i < company_size; ++i) {
            fscanf(fptr,"%hu %hu %s", &(read_company[i]._id), &(read_company[i]._hourly_rate), name);
            if( !strcmp(name,"CEO") ) {
                read_company[i]._role = CEO;
            } else if( !strcmp(name,"ENGINEER") ) {
                read_company[i]._role = ENGINEER;
            } else if( !strcmp(name,"ADMINISTRATION") ) {
                read_company[i]._role = ADMINISTRATION;;
            }
        }
    }
    fclose(fptr);

    printf("\nData read from file\n");
    for(int i = 0; i < company_size; ++i) employee_printf(stdout,read_company+i);
    return 0;
}
