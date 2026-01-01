#include <iostream>
#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;

int getInteger()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}

char getOperation()
{
    char op{};

    do
    {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> op;
    }
    while (op!='+' && op!='-' && op!='*' && op!='/');

    return op;
}

int add(int x, int y){
    return x+y;
}

int subtract(int x, int y){
    return x-y;
}

int multiply(int x, int y){
    return x*y;
}

int divide(int x, int y){
    return x/y;
}

ArithmeticFunction getArithmeticFunction(char op){
    if(op == '+')
        return &add;
    if(op == '-')
        return &subtract;
    if(op == '*')
        return &multiply;
    if(op == '/')
        return &divide;
    
    return nullptr;
}
int main()
{
    int x{ getInteger() };
    char op{ getOperation() };
    int y{ getInteger() };
    
    ArithmeticFunction func {getArithmeticFunction(op)};
    std::cout << "RESULT: " << func(x,y) << std::endl;
    return 0;
}
