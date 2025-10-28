
#include <assert.h>
#include <stdio.h>
#include "int_binary.h"

int main() {
    char buf[33];
    int_to_bin(5, buf);
    assert(strcmp(buf, "00000000000000000000000000000101") == 0);
    assert(bin_to_int("00000001") == 1);
    printf("Integer<->Binary tests passed.\n");
    return 0;
}
