
#include <assert.h>
#include <stdio.h>
#include "endian_conversion.h"

int main() {
    unsigned int val = 0x12345678;
    unsigned int swapped = swap_endian32(val);
    assert(swapped == 0x78563412);
    printf("Endian conversion tests passed.\n");
    return 0;
}
