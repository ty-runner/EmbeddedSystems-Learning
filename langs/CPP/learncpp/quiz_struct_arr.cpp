#include <array>
#include <iostream>
#include <string_view>
struct Item{
    std::string_view name;
    int gold;
};

template <typename std::size_t N>
void printArr(const std::array<Item,N>& items){
    for(const auto& item: items)
        std::cout << "A " << item.name << " costs " << item.gold << " gold.\n";
}
int main(){
    constexpr std::array<Item,4> arr {{
        {"sword", 5},
        {"dagger", 3},
        {"club", 2},
        {"spear", 7},
    }};
    printArr(arr);
    return 0;
}

