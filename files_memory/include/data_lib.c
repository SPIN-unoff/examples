#include "data_lib.h"

const char *role_names[] = {"CEO","ENGINEER","ADMINISTRATION"};

void employee_printf(FILE *stream, const struct employee *const data) {
    fprintf(stream, "Employee:\n");
    fprintf(stream, "\t- id: 0x%.4X\n", data->_id);
    fprintf(stream, "\t- hourly_rate: %d\n", data->_hourly_rate);
    fprintf(stream, "\t- role: %s\n", role_names[data->_role]);
}
