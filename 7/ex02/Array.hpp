#ifndef ARRAY_HPP
 #define ARRAY_HPP

 #include <exception>
 #include <iostream>
 #include <cstdlib>
 #include <ctime>
 template <typename T>
 class Array
 {
	public:
		Array();
		Array(unsigned int size);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();
		T &operator[](unsigned int);
		unsigned int size() const;

		class OutOfBoundException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return("out of bound");
			}
		};
	public:
		T *array;
		unsigned int _length;
 };

 #include "Array.tpp"

#endif