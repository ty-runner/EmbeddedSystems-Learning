/*Write a class named Ball. Ball should have two private member variables,
one to hold a color, and one to hold a radius. 
Also write a function to print out the color and radius of the ball.*/
#include <iostream>
#include <string>
#include <string_view>

class Ball{
private:
    std::string m_color = "black";
    double m_radius = 10.0;

public:
	// Default constructor (color and radius will use default value)
	Ball(double radius):Ball{"black", radius}
	{
            //print();
	}

	// Constructor with both color and radius parameters
	Ball(std::string_view color="black", double radius=10.0)
		: m_color{ color }
		, m_radius{ radius }
	{
            print();
	}
    void print() const
    {
        std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    }
};

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}
