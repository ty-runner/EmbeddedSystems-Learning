#ifndef REGISTER_SIM_H
#define REGISTER_SIM_H
#include "stdint.h"
void reg_write(int idx, uint8_t value);

uint8_t reg_read(int idx);

#endif
