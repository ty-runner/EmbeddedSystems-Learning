#include <stdio.h>
#include "endian_conversion.h"

unsigned int swap_endian32(unsigned int val){
    union uint_data input;
    union uint_data res;
    input.v = val;
    res.v = 0;
    for(int i = 0; i < 4; i++)
        res.bytes[3-i] = input.bytes[i];

    return res.v;
}
