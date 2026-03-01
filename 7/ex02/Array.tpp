#ifndef ARRAY_TPP
 #define ARRAY_TPP

 #include "Array.hpp"

template <typename T>
Array<T>::Array(): _length()
{
	this->array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int size): _length(size)
{
	this->array = new T[size];
}

template <typename T>
Array<T>::Array(const Array& other) : _length(other._length)
{
    array = new T[_length];
    for (unsigned int i = 0; i < _length; i++)
        array[i] = other.array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] this->array;
		array = new T[other._length];
		_length = other._length;
		for (unsigned int i = 0; i < other._length; i++)
		{
			array[i] = other.array[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _length)
	{
		throw(Array::OutOfBoundException());
	}
	return (array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_length);
}

#endif