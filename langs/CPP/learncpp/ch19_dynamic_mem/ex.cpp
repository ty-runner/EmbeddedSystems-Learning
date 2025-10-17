#include <iostream>

struct Monitor {
    int& ref;
    Monitor(int& r) : ref(r) {}
    ~Monitor() { ref *= 2; }
};

int function() {
    int value = 5;
    Monitor m(value);
    return value; // Returns 5, then destructor modifies value
}

int main() {
    std::cout << function() << std::endl; // Outputs 5
    return 0;
}
