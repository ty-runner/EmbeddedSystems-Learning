#include <iostream>

int main()
{
    auto v1 { 12 / 4 }; // int / int => int
    auto v2 { 12 / 4.1 }; // double / int => double

    std::cout << v2;
    return 0;
}
