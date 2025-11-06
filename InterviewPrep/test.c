#include "stdio.h"

const int var = 5;
int main(){
    int* ptr = &var;
    *ptr = 10;
    printf("val: %d\n", var);
}
