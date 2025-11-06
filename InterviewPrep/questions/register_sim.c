#include "stdint.h"

uint8_t reg[8];
void reg_write(int idx, uint8_t value){
    reg[idx] = value;
}

uint8_t reg_read(int idx){
    return reg[idx];
}
