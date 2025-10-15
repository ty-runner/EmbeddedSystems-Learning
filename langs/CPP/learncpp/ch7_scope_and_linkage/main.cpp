#include "iostream"

namespace Foo{
	int doAdd(int x, int y);
}
namespace Goo{
	int doAdd(int x, int y); //actually subtraction but just an example of use case for namesapces
}
int main(){
	printf("Result of %d + %d : %d\n", 5, 10, Foo::doAdd(5,10));
	printf("Result of %d + %d : %d\n", 5, 10, Goo::doAdd(5,10));
}
