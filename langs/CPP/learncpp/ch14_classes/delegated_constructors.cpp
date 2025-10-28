#include <iostream>
#include <string>

class Ball{
    private:
        std::string color {};
        double radius {};
    public:
        Ball(double rad) : 
            Ball("black", rad)
        {}
        Ball(std::string col="black", double rad=10.0) :
            color {col}, radius {rad}
        {
            print();
        }
        void print() const
        {
            std::cout << "Ball(" << color << ", " << radius << ")\n";
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
