#include <stdint.h>

uint8_t reverse_bits8(uint8_t val){
    uint8_t res = 0;
    int p = 0;
    while(p < 8){
        int shamt = 7 - (2*p);
        uint8_t tmp = val & (1 << p);
        res |= shamt < 0 ? tmp >> (shamt*-1) : tmp << shamt;
        p++;
    }
    return res;
}

uint32_t reverse_bits32(uint32_t val){
    uint32_t res = 0;
    int p = 0;
    while(p < 32){
        int shamt = 31 - (2*p);
        uint32_t tmp = val & (1 << p);
        res |= shamt < 0 ? tmp >> (shamt*-1) : tmp << shamt;
        p++;
    }
    return res;
}
