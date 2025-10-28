
#include <assert.h>
#include <stdio.h>
#include "reverse_bits.h"

int main() {
    assert(reverse_bits8(0b00000001) == 0b10000000);
    assert(reverse_bits8(0b10110000) == 0b00001101);
    assert(reverse_bits32(0x00000001) == 0x80000000);
    printf("Reverse Bits tests passed.\n");
    return 0;
}
