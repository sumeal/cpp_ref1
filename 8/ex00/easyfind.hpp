#ifndef EASYFIND_HPP
 #define EASYFIND_HPP

 #include <exception>
 #include <algorithm>
 #include <vector>
 #include <iostream>
 #include <deque>
 #include <list>

class NotFoundException : public std::exception
{
	const char *what() const throw()
	{
		return ("Value not found");
	}
};

template <typename T>
typename T::iterator easyfind(T param, int toFind)
{
	typename T::iterator it = std::find(param.begin(), param.end(), toFind);

	if (it == param.end())
		throw (NotFoundException());
	return (it);
};

#endif