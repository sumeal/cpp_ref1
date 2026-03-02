#include "Span.hpp"

Span::Span() : _N(0)
{

}

Span::Span(unsigned int size) : _N(size)
{

}

Span::Span(const Span &other)
{
	*this = other;
}

Span& Span::operator=(const Span &other)
{
	_N = other._N;
	_vec = other._vec;
	return (*this);
}

Span::~Span()
{

}

void Span::addNumber(unsigned int new_num)
{
	if (_vec.size() >= _N)
	{
		throw(SpanFullException());
	}
	_vec.push_back(new_num);
}

void Span::addMulti(std::vector<unsigned int> new_vec)
{
	if (new_vec.size() + this->_vec.size() > _N)
	{
		throw(SpanFullException());
	}
	for (std::vector<unsigned int>::iterator i = new_vec.begin(); i < new_vec.end(); i++)
	{
		addNumber(*i);
	}
}

int Span::shortestSpan()
{
	if (_vec.size() <= 1)
	{
		throw(SpanEmptyException());
	}
	std::sort(_vec.begin(), _vec.end());

	unsigned int lowestSpan = _vec[1] - _vec[0];
	for (long unsigned int i = 1; i < _vec.size() - 1; i++)
	{
		if (_vec[i + 1] - _vec[i] < lowestSpan)
		{
			lowestSpan = _vec[i + 1] - _vec[i];
		}
	}
	return (lowestSpan);
}

int Span::longestSpan()
{
	if (_vec.size() <= 1)
	{
		throw(SpanEmptyException());
	}
	return (*(std::max_element(_vec.begin(), _vec.end())) - *(std::min_element(_vec.begin(), _vec.end())));
}

unsigned int Span::getN() const
{
	return (_N);
}

void Span::setN(unsigned int newN)
{
	_N = newN;
}

const char* SpanFullException::what() const throw()
{
    return ("Span is full!");
}

const char* SpanEmptyException::what() const throw()
{
    return "Span is empty!";
}