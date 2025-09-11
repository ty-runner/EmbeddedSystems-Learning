#ifndef SUM_5_H   // Prevent multiple inclusion
#define SUM_5_H

#include <vector>
#include <initializer_list>
template <typename T>
T square_and_sum(const std::vector<T>& values) {
    T result = 0;
    for (T v : values) {
        result += v * v;
    }
    return result;
}
// Sum of squares over a vector of ints
template <typename T>
T square_and_sum(std::initializer_list<T> values) {
    T result = 0;
    for (T v : values) {
        result += v * v;
    }
    return result;
}

#endif
