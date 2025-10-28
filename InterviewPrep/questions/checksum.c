#include <stdint.h>
uint8_t xor_checksum(char* arr, int size){
    uint8_t res = 0;
    for(int i = 0; i < size; i++){
        res ^= arr[i];
    }

    return res;
}
