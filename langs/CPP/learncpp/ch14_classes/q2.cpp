#include <iostream>

class Fraction
{
    private:
        int m_numerator{ 0 };
        int m_denominator{ 1 };
    public:
        Fraction(){
            std::cout << "Enter a value for numerator: ";
            std::cin >> m_numerator;
            std::cout << "Enter a value for denominator: ";
            std::cin >> m_denominator;
            std::cout << '\n';
        }

        Fraction(int n, int d) : 
        m_numerator {n}, m_denominator {d}
        {}
        Fraction multiply(const Fraction& f2) const
        {
            return Fraction{ m_numerator * f2.m_numerator, m_denominator * f2.m_denominator };
        }
        void printFraction() const
        {
            std::cout << m_numerator << '/' << m_denominator << '\n';
        }
};

int main()
{
    Fraction f1{ };
    Fraction f2{ };

    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2).printFraction();


    return 0;
}
