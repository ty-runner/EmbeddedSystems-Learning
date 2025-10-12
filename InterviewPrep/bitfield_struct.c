#include "stdio.h"

typedef struct {
    unsigned int MODE : 2; //first 2 bits
    unsigned int ENABLE : 1; //3rd bit
    unsigned int RESERVED : 5; //last 5 bits
} ControlReg;

int main() {
    ControlReg reg = { .MODE = 2, .ENABLE = 0 , .RESERVED = 1}; //RESERVED | ENABLE | MODE -> A=1010, 00001010
    printf("Register = 0x%02X\n", *((unsigned char*)&reg));
}

