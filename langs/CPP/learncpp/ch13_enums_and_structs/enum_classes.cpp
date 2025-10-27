/*Define an enum class named Animal that contains the following animals: pig, chicken, goat, cat, dog, duck.
Write a function named getAnimalName() that takes an Animal parameter and uses a switch statement to return 
the name for that animal as a std::string_view (or std::string if you’re using C++14). Write another function 
named printNumberOfLegs() that uses a switch statement to print the number of legs each animal walks on. 
Make sure both functions have a default case that prints an error message. 
Call printNumberOfLegs() from main() with a cat and a chicken. Your output should look like this:

*/
#include <iostream>
#include <string_view> // C++17
//#include <string> // for C++14

enum class Animal{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};
constexpr std::string_view getAnimalName(Animal animal) // C++17
// const std::string getAnimalName(Animal animal) // C++14
{
    // If C++20 capable, could use `using enum Animal` here to reduce Animal prefix redundancy
    switch (animal)
    {
        case Animal::chicken:
            return "chicken";
        case Animal::duck:
            return "duck";
        case Animal::pig:
            return "pig";
        case Animal::goat:
            return "goat";
        case Animal::cat:
            return "cat";
        case Animal::dog:
            return "dog";

        default:
            return "???";
    }
}
void printNumberofLegs(Animal animal){
    int num_legs;
    switch(animal){
        case Animal::chicken:
        case Animal::duck:
            num_legs = 2;
            break;
        case Animal::cat:
        case Animal::goat:
        case Animal::dog:
            num_legs = 4;
            break;
        default:
            num_legs = -1;

    }
        if(num_legs > 0)
            std::cout << "The animal " << getAnimalName(animal) << " has " << num_legs << " legs.\n"; 
        else
            std::cout << "Given animal not defined!!!!\n";
}
int main(){
    printNumberofLegs(Animal::cat);
    printNumberofLegs(Animal::chicken);

    return 0;
}
