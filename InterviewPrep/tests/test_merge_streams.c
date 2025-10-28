
#include <assert.h>
#include <stdio.h>
#include "merge_streams.h"

int main() {
    Event a[] = {{1,10},{3,30}};
    Event b[] = {{2,20},{4,40}};
    Event out[4];
    merge_streams(a,2,b,2,out);
    assert(out[0].timestamp == 1 && out[3].timestamp == 4);
    printf("Merge streams tests passed.\n");
    return 0;
}
