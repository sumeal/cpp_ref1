#include "MutantStack.hpp"

void basicStackTest()
{
	std::cout << "===== BASIC STACK TEST =====" << std::endl;

	MutantStack<int> stack;

	stack.push(5);
	stack.push(17);

	std::cout << "Top: " << stack.top() << std::endl;

	stack.pop();

	std::cout << "Size after pop: " << stack.size() << std::endl;

	stack.push(3);
	stack.push(5);
	stack.push(737);
	stack.push(0);
	std::cout << "Size after push: " << stack.size() << std::endl;
}

void iteratorTest()
{
	std::cout << "\n===== ITERATOR TEST =====" << std::endl;

	MutantStack<int> stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);

	MutantStack<int>::iterator it = stack.begin();
	MutantStack<int>::iterator ite = stack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void copyTest()
{
	std::cout << "\n===== COPY TEST =====" << std::endl;

	MutantStack<int> original;

	original.push(10);
	original.push(20);
	original.push(30);

	MutantStack<int> copy(original);

	MutantStack<int>::iterator it = copy.begin();
	MutantStack<int>::iterator ite = copy.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void stackCompatibilityTest()
{
	std::cout << "\n===== STD::STACK COMPATIBILITY =====" << std::endl;

	MutantStack<int> stack;

	stack.push(7);
	stack.push(14);
	stack.push(21);

	std::stack<int> s(stack);

	std::cout << "std::stack top: " << s.top() << std::endl;
}

void compareWithList()
{
	std::cout << "\n===== LIST COMPARISON =====" << std::endl;

	MutantStack<int> mstack;
	std::list<int> lst;

	for (int i = 0; i < 5; i++)
	{
		mstack.push(i);
		lst.push_back(i);
	}

	std::cout << "MutantStack:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "\nstd::list:" << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << std::endl;
}

int main()
{
	basicStackTest();
	iteratorTest();
	copyTest();
	stackCompatibilityTest();
	compareWithList();

	return 0;
}