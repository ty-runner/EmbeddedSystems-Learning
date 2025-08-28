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
    std::cout << sum_and_square({1,1,1,1,1}) << "\n";
    std::cout << sum_and_square({1,1,3,3,3}) << "\n";
    std::cout << sum_and_square({1,3,3,3,1}) << "\n";
    std::cout << sum_and_square({1,3,1,1,3}) << "\n";
    std::cout << sum_and_square({3,3,3,1,1}) << "\n";
    std::cout << sum_and_square({3,3,1,3,3}) << "\n";
    std::cout << sum_and_square({3,1,1,3,1}) << "\n";
    std::cout << sum_and_square({3,1,3,1,3}) << "\n";

    std::cout << avg_of_signals({
    sum_and_square({1,1,1,1,1}),
    sum_and_square({1,1,3,3,3}),
    sum_and_square({1,3,3,3,1}),
    sum_and_square({1,3,1,1,3}),
    sum_and_square({3,3,3,1,1}),
    sum_and_square({3,3,1,3,3}),
    sum_and_square({3,1,1,3,1}),
    sum_and_square({3,1,3,1,3})
    }) << "\n";
    return 0;
}
