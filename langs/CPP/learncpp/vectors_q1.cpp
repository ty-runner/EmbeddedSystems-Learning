#include <vector>
#include <iostream>

int main(){
    std::vector<char> arr = {'h','e','l','l','o'};

    std::cout << "The array has " << std::size(arr) << " elements" << std::endl;
    std::cout << arr.at(1) << std::endl;
    return 0;
}
