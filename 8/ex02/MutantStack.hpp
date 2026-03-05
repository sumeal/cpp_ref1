#ifndef MUTANTSTACK_HPP
 #define MUTANTSTACK_HPP

 #include <stack>
 #include <deque>
 #include <iostream>

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