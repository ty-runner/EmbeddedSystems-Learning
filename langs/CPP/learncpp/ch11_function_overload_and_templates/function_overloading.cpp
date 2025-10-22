#include <iostream>
template<typename T>
T mult(T x, int y){
	return x * y;
}

template<typename T>
T add(T x, T y){
	return x + y;
}

template<typename T, typename U>
auto sub(T x, U y){
	return x - y;
}
int main(){
	int x = 5;
	float y = 6.7;

	std::cout << add(x,x) << std::endl;
	std::cout << add(y,y) << std::endl;
	std::cout << mult(y,x) << std::endl;

	std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';
	return 0;
}
