#include <iostream>
#include <vector>
#include <algorithm> // For std::for_each

int main() {
    std::vector<int> myVector = {10, 20, 30, 40, 50};

    // Remove the element at index 2 (which is 30)
    int indexToRemove = 2;
    if (indexToRemove >= 0 && indexToRemove < myVector.size()) {
        myVector.erase(myVector.begin() + indexToRemove);
    } else {
        std::cout << "Invalid index." << std::endl;
    }

    // Print the modified vector
    std::cout << "Vector after removing element at index " << indexToRemove << ": ";
    for (int val : myVector) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
