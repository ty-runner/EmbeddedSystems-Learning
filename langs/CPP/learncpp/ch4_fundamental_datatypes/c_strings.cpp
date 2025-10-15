#include <iostream>

void printString(const char str[]){
    const char* base = str;
    while(*str != '\0'){
        str++;
    }
    while(str != base){
        std::cout << *str;
        str--;
    }
    std::cout << *str;
}

int main(){
    printString("hi");
    std::cout << "\n";
    const char str[] {"hello!"};
    printString(str);
    return 0;
}
