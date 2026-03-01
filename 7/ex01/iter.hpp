#ifndef ITER_HPP
 #define ITER_HPP

 #include <iostream>

template <typename T, typename F>
void iter(T *addr, const int length, F func)
{
	for (int i = 0; i < length; i++)
	{
		func(addr[i]);
	}
}

#endif