
#include <assert.h>
#include <stdio.h>
#include "checksum.h"

int main() {
    unsigned char data1[] = {1, 2, 3};
    assert(xor_checksum(data1, 3) == (1 ^ 2 ^ 3));
    unsigned char data2[] = {0xAA, 0x55};
    assert(xor_checksum(data2, 2) == (0xFF));
    printf("Checksum tests passed.\n");
    return 0;
}
