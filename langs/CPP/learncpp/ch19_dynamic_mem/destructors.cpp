#include <iostream>
#include <cassert>
#include <cstddef>

class IntArray{
private:
    int* m_array;
    int m_length;
public:
    IntArray(int length){ //constructor
        assert(length > 0);

        m_array = new int[length] {};
        m_length = length;
    }

    ~IntArray(){ //destructor
        delete[] m_array;
    }

    int getLength() { return m_length;}
    void setValue(int idx, int data) { m_array[idx] = ((idx < m_length) ? data : 0);}
    int getValue(int idx) { return ((idx < m_length) ? m_array[idx] : -1);}
};

int main()
{
	IntArray ar ( 10 ); // allocate 10 integers
	for (int count{ 0 }; count < ar.getLength(); ++count)
		ar.setValue(count, count+1);

	std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n';

	return 0;
} // ar is destroyed here, so the ~IntArray() destructor function is called here
