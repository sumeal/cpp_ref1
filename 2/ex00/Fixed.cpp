#include "Fixed.hpp"
#include <iostream>

const int Fixed::fracBit = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	this->fixNumber = 0;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return this->fixNumber;
}

void Fixed::setRawBits(int const raw) {
	this->fixNumber = raw;
}