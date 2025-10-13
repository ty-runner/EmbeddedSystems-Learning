#include <stdio.h>

void add()    { printf("Add\n"); }
void remve() { printf("Remove\n"); }
void update() { printf("Update\n"); }

int main() {
    // Array of function pointers
    void (*operations[3])() = { add, remve, update };

    for (int i = 0; i < 3; i++) {
        operations[i](); // calls add(), remve(), update()
    }

    return 0;
}

