#include "stdio.h"

#define BIT(n) (1U<<n)


int main(){
    int x = 15;
    printf("X: %d\n", x);
    //1. clear bit 3
    x &= ~BIT(3);
    printf("X: %d\n", x);
    //2. set bit 3
    x |= BIT(1);
    printf("X: %d\n", x);
    //3. toggle bit 1
    x ^= BIT(1);
    printf("X: %d\n", x);
}
