/*#include <iostream>

enum class FruitType
{
	apple,
	banana,
	cherry
};

class Fruit
{
private:
	FruitType m_type { };
	int m_percentageEaten { 0 };

public:
	Fruit(FruitType type) :
		m_type { type }
	{
	}

	FruitType getType() { return m_type; }
	int getPercentageEaten() { return m_percentageEaten; }

	bool isCherry() { return m_type == FruitType::cherry; }

};

int main()
{
	Fruit apple { FruitType::apple };

	if (apple.getType() == FruitType::apple)
		std::cout << "I am an apple";
	else
		std::cout << "I am not an apple";

	return 0;
}*/ //BEFORE 
#include <iostream>


//AFTER
class Fruit
{
public:
    enum FruitType
    {
        apple,
        banana,
        cherry
    };
private:

	FruitType m_type { };
	int m_percentageEaten { 0 };

public:
	Fruit(FruitType type) :
		m_type { type }
	{
	}

	FruitType getType() { return m_type; }
	int getPercentageEaten() { return m_percentageEaten; }

	bool isCherry() { return m_type == FruitType::cherry; }

};

int main()
{
	Fruit apple { Fruit::apple };

	if (apple.getType() == Fruit::apple)
		std::cout << "I am an apple";
	else
		std::cout << "I am not an apple";

	return 0;
}
