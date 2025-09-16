#include <array>
#include <iostream>

template <typename T, std::size_t N>
void printArray(const std::array<T,N>& arr){
    if(N == 0){
        std::cout << "FUNCTION OF NO LENGTH" << std::endl;
        return;
    }
    std::cout << "The array (";
    for(int i = 0; i < N; i++){
        if(i == N-1)
            std::cout << arr[i] << ")";
        else
            std::cout << arr[i] << ", ";
    }
    std::cout << " has length " << N << std::endl;
}
int main()
{
    constexpr std::array arr1 { 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}
