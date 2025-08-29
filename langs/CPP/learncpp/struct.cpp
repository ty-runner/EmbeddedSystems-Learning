#include <iostream>

struct Date{
    int year{};
    int month{};
    int day{};

    void print(){
        std::cout << year << "/" << month << "/" << day;
    }
};

int main(){
    Date today {2025, 8, 29};

    today.print();
    return 0;
}
