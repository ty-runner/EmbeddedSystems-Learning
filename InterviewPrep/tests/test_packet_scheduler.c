
#include <assert.h>
#include <stdio.h>
#include "packet_scheduler.h"

int main() {
    Task tasks[] = {{1,2}, {2,1}, {3,3}};
    int order[3];
    int n = schedule(tasks, 3, order);
    assert(n == 3);
    assert(order[0] == 2); // highest priority first
    printf("Packet scheduler tests passed.\n");
    return 0;
}
