#include <assert.h>
#include <stdio.h>
#include "bit_count.h"

int main() {
    assert(bit_count(0x0) == 0);
    assert(bit_count(0xFFFFFFFF) == 32);
    assert(bit_count(0xA5A5A5A5) == 16);
    printf("Bit Count tests passed.\n");
    return 0;
}
