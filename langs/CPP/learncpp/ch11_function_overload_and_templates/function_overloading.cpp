#include <iostream>
template<typename T>
T add(T x, T y){
	return x + y;
}

int main(){
	int x = 5;
	float y = 6.7;

	std::cout << add(x,x) << std::endl;
	std::cout << add(y,y) << std::endl;
	std::cout << add(x,y) << std::endl;

	return 0;
}
