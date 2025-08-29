#include <iostream>
#include "sum_5.h"

double avg_of_signals(const std::vector<int>& signals) {
    if (signals.empty()) return 0.0;  // guard against divide by zero
    
    double res = 0;
    for (int s : signals) {
        res += s;
    }
    return res / signals.size();
}

int main(){
    std::cout << square_and_sum({1,1,1,1,1}) << "\n";
    std::cout << square_and_sum({1,1,3,3,3}) << "\n";
    std::cout << square_and_sum({1,3,3,3,1}) << "\n";
    std::cout << square_and_sum({1,3,1,1,3}) << "\n";
    std::cout << square_and_sum({3,3,3,1,1}) << "\n";
    std::cout << square_and_sum({3,3,1,3,3}) << "\n";
    std::cout << square_and_sum({3,1,1,3,1}) << "\n";
    std::cout << square_and_sum({3,1,3,1,3}) << "\n";

    std::cout << avg_of_signals({
    square_and_sum({1,1,1,1,1}),
    square_and_sum({1,1,3,3,3}),
    square_and_sum({1,3,3,3,1}),
    square_and_sum({1,3,1,1,3}),
    square_and_sum({3,3,3,1,1}),
    square_and_sum({3,3,1,3,3}),
    square_and_sum({3,1,1,3,1}),
    square_and_sum({3,1,3,1,3})
    }) << "\n";
    return 0;
}
