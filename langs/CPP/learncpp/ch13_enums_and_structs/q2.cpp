#include <iostream>
#include <string>
enum class Animal{
	pig,
	chicken,
	goat,
	cat,
	dog,
	duck,

	maxAnimals,
};

std::string getAnimalName(Animal animal){
	switch(animal){
		case Animal::pig:
			return "pig";
		case Animal::chicken:
			return "chix";

		case Animal::goat:
			return "goat";
		case Animal::cat:
			return "cat";

		case Animal::dog:
			return "dog";
		case Animal::duck:
			return "duck";
		default:
			return "?";
	}
}
void printNumberOfLegs(Animal animal){
	std::cout << "A " << getAnimalName(animal) << " has "; 
	int res;
	switch(animal){
		case Animal::pig:
		case Animal::goat:
		case Animal::cat:
		case Animal::dog:
			res = 4;
			break;
		case Animal::chicken:
		case Animal::duck:
			res = 2;
			break;
		default:
			res = 0;
	}
	std::cout << res << " legs" << std::endl;
}
int main(){
        printNumberOfLegs(Animal::cat);
        printNumberOfLegs(Animal::chicken);
	return 0;
}
