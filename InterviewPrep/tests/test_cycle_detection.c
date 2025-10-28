
#include <assert.h>
#include <stdio.h>
#include "cycle_detection.h"

int main() {
    Node a={1,NULL}, b={2,NULL}, c={3,NULL};
    a.next=&b; b.next=&c; c.next=NULL;
    assert(has_cycle(&a)==0);
    c.next=&a;
    assert(has_cycle(&a)==1);
    printf("Cycle detection tests passed.\n");
    return 0;
}
