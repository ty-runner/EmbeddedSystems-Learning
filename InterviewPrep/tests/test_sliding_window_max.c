
#include <assert.h>
#include <stdio.h>
#include "sliding_window_max.h"

int main() {
    int arr[] = {1,3,-1,-3,5,3,6,7};
    int out[8];
    int n = sliding_window_max(arr, 8, 3, out);
    assert(out[0] == 3 && out[n-1] == 7);
    printf("Sliding Window Max tests passed.\n");
    return 0;
}
