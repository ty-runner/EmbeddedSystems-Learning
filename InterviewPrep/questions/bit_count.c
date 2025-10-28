#include "bit_count.h"

int bit_count(uint32_t val){
    int count = 0;
    while(val){ //while not 0
        count += (val & 1);
        val >>= 1;
    }
    return count;
}
