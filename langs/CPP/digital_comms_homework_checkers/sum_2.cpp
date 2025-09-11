#include <iostream>
#include "sum_5.h"

template <typename T>
T avg_of_signals(const std::initializer_list<T>& signals) {
    //if (signals.empty()) return 0.0;  // guard against divide by zero
    
    T res = 0.0;
    for (T s : signals) {
        res += s;
    }
    std::cout << "SUM OF SQUARES: " << res << std::endl;
    return res / signals.size();
}

int main(){
    std::cout << square_and_sum({1.0,0.0}) << "\n";
    std::cout << square_and_sum({-1.0,0.0}) << "\n";
    std::cout << square_and_sum({2.0,1.732}) << "\n";
    std::cout << square_and_sum({0.0,1.732}) << "\n";
    std::cout << square_and_sum({-2.0,1.732}) << "\n";
    std::cout << square_and_sum({2.0,-1.732}) << "\n";
    std::cout << square_and_sum({0.0,-1.732}) << "\n";
    std::cout << square_and_sum({-2.0,-1.732}) << "\n";

    std::cout << avg_of_signals({
    square_and_sum({1.0,0.0}),
    square_and_sum({-1.0,0.0}),
    square_and_sum({2.0,1.732}),
    square_and_sum({0.0,1.732}),
    square_and_sum({-2.0,1.732}), 
    square_and_sum({2.0,-1.732}),
    square_and_sum({0.0,-1.732}),
    square_and_sum({-2.0,-1.732})
    }) << "\n";
    return 0;
}
