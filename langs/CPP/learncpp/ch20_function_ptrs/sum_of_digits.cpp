#include <iostream>

int sum_of_digits(int input){
    if(input < 10)
        return input;
    return sum_of_digits(input / 10) + input % 10;
}

int main(){
    std::cout << "RES: " << sum_of_digits(93427);
    return 0;
}
