#include "stdio.h"

void func(int x){
    int y = 20;
    int* p = &y;
    static int z = 99;
    static int z1 = 99;
    printf("x=%d, y=%d, z=%d\n\n", x, *p, z);
    printf("x=%p, y=%p, z=%p, z1=%p\n", &x, p, &z, &z1);
}
int main() {
    int a = 5;
    func(a);
    return 0;
}

