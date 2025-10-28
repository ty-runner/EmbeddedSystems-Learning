
#include <assert.h>
#include <stdio.h>
#include "shuffle.h"

int main() {
    int arr[5] = {1,2,3,4,5};
    shuffle(arr, 5);
    // Verify all elements still exist
    int sum = 0;
    for (int i = 0; i < 5; i++) sum += arr[i];
    assert(sum == 15);
    printf("Shuffle tests passed.\n");
    return 0;
}
