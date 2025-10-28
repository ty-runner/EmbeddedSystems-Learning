
#include <assert.h>
#include <stdio.h>
#include "fixed_point.h"

int main() {
    int a = to_fixed(1.5);
    int b = to_fixed(2.0);
    int c = fixed_mul(a, b);
    double res = from_fixed(c);
    assert(res > 2.99 && res < 3.01);
    printf("Fixed-point arithmetic tests passed.\n");
    return 0;
}
