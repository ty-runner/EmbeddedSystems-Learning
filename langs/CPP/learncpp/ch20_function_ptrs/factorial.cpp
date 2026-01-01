#include <iostream>

int factorial(int i){
    if(i == 1)
        return 1;
    return i * factorial(i-1);
}

int main(){
    for(int i = 1; i < 7; i++){
        std::cout << "FACTORIAL OF " << i << ": " << factorial(i) << "\n";
    }
    return 0;
}
