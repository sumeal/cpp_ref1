#ifndef MUTANTSTACK_HPP
 #define MUTANTSTACK_HPP

 #include <stack>
 #include <deque>
 #include <iostream>
 #include <list>

/*
	This sets a default container.
	If the user does not specify a container, it will use the std::deque

	This is actually the same default container used by std::stack.
	Internally std::stack is defined like this
*/

template <typename T, class container=std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){};
		~MutantStack(){};
		MutantStack(const MutantStack &stack)
		{
			*this = stack;
		}
		typedef typename container::iterator iterator;
		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}
};

#endif