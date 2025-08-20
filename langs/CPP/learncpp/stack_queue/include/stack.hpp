#ifndef STACK_HPP
#define STACK_HPP

#include "container.hpp"
#include <vector>

template <typename T>

class Stack : public Container<T> {
    private:
        std::vector<T> data;

    public:
        void push(const T& item) override{
            data.push_back(item);
        }
        const T& front() const override{
            return data.back();
        }
 };

#endif
