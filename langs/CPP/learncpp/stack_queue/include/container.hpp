#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <cstddef>  // for size_t

template <typename T>
class Container {
public:
    virtual ~Container() = default;

    virtual void push(const T& item) = 0;
    virtual void pop() = 0;
    virtual const T& front() const = 0;  // peek at next element
    //virtual bool isEmpty() const = 0;
    //virtual size_t size() const = 0;
};

#endif // CONTAINER_HPP

