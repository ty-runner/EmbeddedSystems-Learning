#ifndef SUM_5_H   // Prevent multiple inclusion
#define SUM_5_H

#include <vector>

// Sum of squares over a vector of ints
int sum_and_square(const std::vector<int>& values) {
    int result = 0;
    for (int v : values) {
        result += v * v;
    }
    return result;
}

#endif
