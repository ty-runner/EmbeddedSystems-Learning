#include <iostream>
#include <vector>

// Write your printElement function here
template <typename T, typename U>
void printElement(const std::vector<T>& arr, U index){
    size_t size = arr.size();
    if(index < 0 || index >= size)
        std::cout << "INDEX OUT OF BOUNDS" << std::endl;
    else
        std::cout << arr[index] << std::endl;
    return;
}
        
int main()
{
    std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}
