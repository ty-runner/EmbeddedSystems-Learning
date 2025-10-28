#include <iostream>
#include <string>

class Ball{
    private:
        std::string color {"black"};
        double radius {10.0};
    public:
        Ball(){
            print();
        }
        Ball(std::string col) :
            color {col}
        {
            print();
        }

        Ball(double rad) :
            radius {rad}
        {
            print();
        }

        Ball(std::string col, double rad) :
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
