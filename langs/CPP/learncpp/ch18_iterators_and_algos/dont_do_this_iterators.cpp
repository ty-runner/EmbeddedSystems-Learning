#include <vector>
#include <iostream>
#include <iterator>
int main()
{
    std::vector v { 0, 1, 2, 3 };
    int x = 10;
    for (auto num : v) // implicitly iterates over v
    {
        if (num % 2 == 0)
            v.push_back(num + 1); // when this invalidates the iterators of v, undefined behavior will result
        auto begin = std::begin(v);
        auto end = std::end(v);
        while(begin != end){
            std::cout << *begin;
            begin++;
        }
        std::cout << std::endl;
    }

    return 0;
}
