#ifndef __DATA_LIB__
#define __DATA_LIB__

#include <stdio.h>
#include <stdint.h>

enum position {
    CEO = 0,
    ENGINEER,
    ADMINISTRATION
};

struct employee {
    uint16_t _id;
    uint16_t _hourly_rate;
    enum position _role;
};

void employee_printf(FILE *stream, const struct employee *const data);

#endif
