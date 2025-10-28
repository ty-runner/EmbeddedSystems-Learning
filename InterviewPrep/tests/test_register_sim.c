
#include <assert.h>
#include <stdio.h>
#include "register_sim.h"

int main() {
    reg_write(0, 0xAB);
    assert(reg_read(0) == 0xAB);
    reg_write(7, 0xFF);
    assert(reg_read(7) == 0xFF);
    printf("Register simulation tests passed.\n");
    return 0;
}
