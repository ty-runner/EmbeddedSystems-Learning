#include <iostream>
#include <cassert>

template <int I>
constexpr factorial(){
	static_assert(I >= 0);
	int res = I;
	int cpy = I;
	while(cpy > 1){
		cpy--;
		res*=cpy;
	}
	if(I == 0) res = 1;
	return res;
}
// define your factorial() function template here

int main()
{
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    factorial<-3>(); // should fail to compile

    return 0;
}
