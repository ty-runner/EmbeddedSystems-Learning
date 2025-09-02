#include <iostream>
#include <cmath>
//Write a class named Point2d. Point2d should contain two member variables of type double: m_x, and m_y, both defaulted to 0.0.

class Point2d{
private: 
    double m_x = 0.0;
    double m_y = 0.0;
public:
    Point2d() = default;
    Point2d(double x, double y): m_x {x}, m_y {y} {}

    void print() const{
        std::cout << "X: " << m_x << " Y: " << m_y << std::endl;
    }

    double distanceTo(Point2d& second) const{ //std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)). 
        return (std::sqrt((m_x - second.m_x)* (m_x - second.m_x)+ (m_y - second.m_y)*(m_y - second.m_y)));
    }
};

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}
