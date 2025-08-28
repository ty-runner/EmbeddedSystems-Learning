#include <iostream>
#include "sum_5.h"

template <typename T>
std::vector<T> vector_diff(const std::vector<T>& a, const std::vector<T>& b) {
    std::vector<T> res;
    if (a.size() != b.size()) {
        std::cerr << "Error: vectors must be the same size\n";
        return res;
    }
    res.resize(a.size());
    for (size_t i = 0; i < a.size(); i++) {
        res[i] = a[i] - b[i];
    }
    return res;
}

template <typename T>
std::vector<T> squared_euclid_distance(const std::vector<std::vector<T>>& signals) {
    std::vector<T> res(signals.size(), 0);
    if (signals.empty()) return res;

    T total = 0;
    const std::vector<T>& base_signal = signals[0];
    for (size_t i = 1; i < signals.size(); i++) {
        std::vector<T> diff = vector_diff(base_signal, signals[i]);
        int temp = square_and_sum(diff);
        total += temp;
        res[i] = temp;
    }
    std::cout << "Total euclid distances from s0 = " << total << std::endl;
    return res;
}

int main() {
    // Populate the 2D vector (8 signals, each of length 5)
    std::vector<std::vector<int>> signals = {
        {-1,-1,-1,-1,-1},
        {-1,-1, 3,-3, 3},
        {-1, 3,-3, 3,-1},
        {-1, 3, 1, 1, 3},
        { 3,-3, 3,-1,-1},
        { 3,-3,-1,-3, 3},
        { 3, 1, 1, 3,-1},
        { 3, 1,-3, 1, 3}
    };

    std::vector<int> distances = squared_euclid_distance(signals);

    std::cout << "Distances: ";
    for (int d : distances) std::cout << d << " ";
    std::cout << std::endl;

    return 0;
}
