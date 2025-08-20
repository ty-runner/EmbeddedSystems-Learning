#include "stack.hpp"
#include <iostream>
//#include "..include/queue.hpp"

int main(){
    Stack<int> stack_int;
    Stack<float> stack_float;
    Stack<double> stack_double;

    stack_int.push(1);
    stack_int.push(2);

    int val = stack_int.front();
    std::cout << val;
    stack_int.pop();
    val = stack_int.front();
    std::cout << val;
    
    return 0;
}
