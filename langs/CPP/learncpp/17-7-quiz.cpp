#include <iostream>

namespace ProgramData{
    const int perfSquares[] {0, 1, 4, 9};
}

bool matchSquare(int input){
    for(auto& square : ProgramData::perfSquares){
        if(input == square)
            return true;
    }
    return false;
}
int main()
{
    while (true)
    {
        std::cout << "Enter a single digit integer, or -1 to quit: ";
        int input{};
        std::cin >> input;
        if(input == -1){
            std::cout << "Bye" << std::endl;
            return 0;
        }
        if(matchSquare(input))
            std::cout << input << " is a perfect square" << std::endl;
        else
            std::cout << input << " is not a perfect square" << std::endl;
    }
    return 0;
}
            
