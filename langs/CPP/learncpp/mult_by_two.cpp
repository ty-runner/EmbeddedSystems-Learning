#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter a number: "; // ask user for a number
    int x, y; // define variable x to hold user input
    std::cin >> x; // get number from keyboard and store it in variable x
    y = x * 2;
    std::cout << x << " Times 2 =  " << y << '\n';

    return 0;
}
