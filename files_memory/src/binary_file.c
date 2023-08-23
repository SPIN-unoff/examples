#include <stdio.h>
#include <stdlib.h>
#include <data_lib.h>

int main( int argc, char *argv[] ) {

    FILE *fptr;

    /**
     * Writing
     */

    fptr = fopen("./cache/binary_file.dat", "wb");

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
        company[i]._id = i;
        company[i]._hourly_rate = 10*i;
        company[i]._role = 1 + (i/2) % 2;
    }
    // Print data before writing
    printf("\nData written to file\n");
    for(int i = 0; i < company_size; ++i) employee_printf(stdout,company+i);
    // write the whole array in a file in binary format
    fwrite(&company, sizeof(struct employee), company_size, fptr);
    fclose(fptr);

    /**
     * Reading
     */

    // Alternative way to open and check a file in the same line
    // Personally discouraged
    if((fptr = fopen("./cache/binary_file.dat", "rb")) == NULL) {
        // It is good practice to redirect errors on the `stderr` stream
        fprintf(stderr,"Error opening file!\n");
        return 1;
    } else {
        printf("File has been successfully opened!\n");
    }

    // prepare memory to read in the file
    struct employee read_company[company_size];
    // read from file
    fread(&read_company,sizeof(struct employee), company_size, fptr);
    fclose(fptr);

    printf("\nData read from file\n");
    for(int i = 0; i < company_size; ++i) employee_printf(stdout,read_company+i);

    return 0;
}
