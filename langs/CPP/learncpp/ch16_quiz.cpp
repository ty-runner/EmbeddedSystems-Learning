#include <cassert>
#include <iostream>
#include <vector>

namespace Items{
    enum Type{
        health_potions,
        torches,
        arrows,
        max_items
    };
}

int countTotalItems(const std::vector<int>& inventory){
    int sum = 0;
    for(auto e: inventory)
        sum += e;
    return sum;
}
void printItemList(const std::vector<int>& inventory){

    std::cout << "You have " << inventory[0] << " health potions\n";
    std::cout << "You have " << inventory[1] << " torches\n";
    std::cout << "You have " << inventory[2] << " arrows\n";
}
int main(){
    std::vector inventory {1, 5, 10};
    assert(std::size(inventory) == Items::max_items); // make sure our inventory has the correct number of initializers
    printItemList(inventory);
    std::cout << "You have " << countTotalItems(inventory) << " total items\n";
    return 0;
}
