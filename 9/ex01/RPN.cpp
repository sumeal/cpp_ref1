#include "RPN.hpp"

RPN::RPN() {};

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	_stack = other._stack;
	return (*this);
}

RPN::~RPN() {};

void RPN::isInputValid(std::string input)
{
	if (input.empty() || input[0] == ' ' || input[input.size() - 1] == ' ')
	{
		throw(invalidInputException());
	}

	for (std::size_t i = 0; i < input.size(); i++)
	{
		if (i % 2 == 0)
		{
			if (!(input[i] >= '0' && input[i] <= '9') &&
				input[i] != '+' && input[i] != '-' &&
				input[i] != '*' && input[i] != '/')
				throw(invalidInputException());
		}
		else
		{
			if (input[i] != ' ')
				throw(invalidInputException());
		}
	}
}

void RPN::runRPN(std::string input)
{
	int intCounter = 0;
	try
	{
		isInputValid(input);
		for (int i = 0; i < (int)input.size(); i++)
		{
			switch(input[i])
			{
				case '0' ... '9':
					_stack.push(input[i] - '0');
					++intCounter;
					break;
				case '+': case '-': case '/': case '*':
					if (intCounter <= 1)
						throw(invalidInputException());
					--intCounter;
					runOperation(input[i]);
					break;
				case ' ':
					break ;
			}
		}
		if (_stack.size() != 1)
			throw (invalidInputException());
		else
			std::cout << _stack.top() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int RPN::operate(char operation, int a, int b)
{
	switch(operation)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '/':
			return a / b;
		case '*':
			return a * b;
		default:
			return (0);
	}
}

void RPN::runOperation(char operation)
{
	int tmp1 = _stack.top();
	_stack.pop();
	int tmp2 = _stack.top();
	_stack.pop();
	_stack.push(operate(operation, tmp2, tmp1));
}
