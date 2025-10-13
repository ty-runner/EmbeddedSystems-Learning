#include "stdio.h"

int add(int a, int b){
    return a+b;
}


int main(){
    int (*fptr)(int,int);

    fptr = &add;

    printf("The sum of %d, %d, is %d\n", 10, 20, fptr(10,20));
}
