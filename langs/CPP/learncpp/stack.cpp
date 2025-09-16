#include <iostream>
#include <vector>

void printStack(const std::vector<int>& stack)
{
	if (stack.empty()) // if stack.size == 0
		std::cout << "Empty";
    std::cout << "||| ";
	for (auto element : stack)
		std::cout << element << ' ';
    std::cout << "\n";
}

int main()
{
	std::vector<int> stack{}; // empty stack

	printStack(stack);

	stack.push_back(1); // push_back() pushes an element on the stack
    std::cout << "Push 1 ";
	printStack(stack);

	stack.push_back(2);
    std::cout << "Push 2 ";
	printStack(stack);

	stack.push_back(3);
    std::cout << "Push 3 ";
	printStack(stack);

	stack.pop_back(); // pop_back() pops an element off the stack
    std::cout << "Pop ";
	printStack(stack);

	stack.push_back(4);
    std::cout << "Push 4 ";
	printStack(stack);

	stack.pop_back();
    std::cout << "Pop ";
	printStack(stack);

	stack.pop_back();
    std::cout << "Pop ";
	printStack(stack);

	stack.pop_back();
    std::cout << "Pop ";
	printStack(stack);

	return 0;
}
