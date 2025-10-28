
#include <assert.h>
#include <stdio.h>
#include "detect_duplicates.h"

int main() {
    int ids[] = {1,2,3,2,4};
    assert(has_duplicates(ids, 5) == 1);
    int ids2[] = {1,2,3,4,5};
    assert(has_duplicates(ids2, 5) == 0);
    printf("Duplicate detection tests passed.\n");
    return 0;
}
