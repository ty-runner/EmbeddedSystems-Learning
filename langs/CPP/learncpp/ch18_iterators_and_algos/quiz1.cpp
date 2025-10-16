/*
Write a program that:

Asks the user how many names they wish to enter.
Dynamically allocates a std::string array.
Asks the user to enter each name.
Calls std::sort to sort the names (See 18.1 -- Sorting an array using selection sort and 17.9 -- Pointer arithmetic and subscripting)
Prints the sorted list of names.
*/

#include <algorithm> // std::sort
#include <cstddef>
#include <iostream>
#include <string>

std::size_t getNameCount(){
    std::cout << "How many names would you like to enter? ";
    std::size_t length;
    std::cin >> length;
    return length;
}

void getNames(std::string* names, std::size_t length)
{
    for (std::size_t i{ 0 }; i < length; ++i)
    {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, names[i]);
    }
}

int main(){
    std::size_t length = getNameCount();
    auto* names {new std::string[length]{} };
    getNames(names, length);
    std::sort(names, names + length);
    for(int i = 0; i < length; i++){
        std::cout << names[i] << std::endl;
    }
    delete[] names;
    return 0;
}

