#include "MutantStack.hpp"

int main()
{
	MutantStack<int> stack;
	stack.push(5);
	stack.push(42);
	std::cout << stack.top() << std::endl;
	stack.pop();
	std::cout << stack.size() << std::endl;
	stack.push(1);
	stack.push(3);
	stack.push(5);
	MutantStack<int>::iterator it = stack.begin();
	MutantStack<int>::iterator ite = stack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(stack);
	return (0);
}