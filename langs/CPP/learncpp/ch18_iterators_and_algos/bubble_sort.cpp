#include <iostream>
#include <iterator>
#include <utility>

int main(){
    int arr[]{30, 50, 20, 10, 40};
    constexpr int length{ static_cast<int>(std::size(arr)) };
    int length_copy = length;
    for(int i = 0; i < length - 1; i++){
        for(int startIndex{0}; startIndex < length_copy -1; ++startIndex){
            if(arr[startIndex] > arr[startIndex + 1])
                std::swap(arr[startIndex], arr[startIndex + 1]);

        }

        length_copy--;
    }
	for (int index{ 0 }; index < length; ++index)
		std::cout << arr[index] << ' ';

	std::cout << '\n';

    return 0;
}
