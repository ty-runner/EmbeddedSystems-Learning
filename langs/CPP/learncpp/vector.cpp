#include <vector>
#include <iostream>

int main()
{
    std::vector<int> arr (3);
	std::cout << "Enter 3 integers: ";
	std::cin >> arr[0] >> arr[1] >> arr[2];
    std::cout << "SUM OF 3 IS: " << arr[0] + arr[1] + arr[2] << std::endl;
    std::cout << "PRODUCT OF 3 IS: " << arr[0] * arr[1] * arr[2] << std::endl;
    return 0;
}
