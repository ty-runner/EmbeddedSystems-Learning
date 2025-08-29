#ifndef SUM_5_H   // Prevent multiple inclusion
#define SUM_5_H

#include <vector>

// Sum of squares over a vector of ints
int square_and_sum(const std::vector<int>& values) {
    int result = 0;
    for (int v : values) {
        result += v * v;
    }
    return result;
}

#endif
