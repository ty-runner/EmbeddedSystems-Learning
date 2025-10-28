#include <iostream>
#include <string>

class Ball{
    private:
        std::string color {};
        double radius {};
    public:
        Ball(std::string col, double rad) :
            color {col}, radius {rad}
        {
            std::cout << "Ball constructed \n";
        }
        std::string getColor(){ return color; }
        double getRadius() { return radius;}
};


void print(Ball ball){
    std::cout << "Ball(" << ball.getColor() << ", " << ball.getRadius() << ")\n";
}


int main()
{
	Ball blue { "blue", 10.0 };
	print(blue);

	Ball red { "red", 12.0 };
	print(red);

	return 0;
}
