#include <iostream>

void print(){
    std::cout << "hiiiiii" <<std::endl;
}


namespace local{
    void print(){
        std::cout << "HIIIIII" << std::endl;
    }
}


int main(){
    local::print();
    ::print();
    print();
    return 0;
}
