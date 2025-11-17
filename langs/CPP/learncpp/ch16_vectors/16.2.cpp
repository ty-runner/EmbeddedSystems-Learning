#include <iostream>
#include <vector>

void readValues(std::vector<int>& res){
    std::cout << "Enter 3 integers: ";
    std::cin >> res[0] >> res[1] >> res[2];
}

int main(){
    std::vector<int> res (3);

    readValues(res);

    std::cout << "SUM: " << res[0] + res[1] + res[2] << "\n";
    std::cout << "PROD: " << res[0] * res[1] * res[2] << "\n";

    return 0;
}
