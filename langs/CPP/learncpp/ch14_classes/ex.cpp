#include <iostream>

class Something
{
private:
    int m_x{};

public:

    Something() // constructors must be non-const
    {
        m_x = 5; // okay to modify members in non-const constructor
    }
    int getX() const { return m_x; } // const
};

int main()
{
    const Something s{}; // const object, implicitly invokes (non-const) constructor

    std::cout << s.getX(); // prints 5

    return 0;
}
