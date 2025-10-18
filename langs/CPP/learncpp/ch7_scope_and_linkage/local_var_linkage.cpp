#include <iostream>

int main()
{
    static int x { 2 };
    std::cout << "Outer x = " << x << '\n';

    {
        int x { 3 };
        std::cout << "Inner x = " << x << '\n';
    }

    std::cout << "Outer x again = " << x << '\n';
}

