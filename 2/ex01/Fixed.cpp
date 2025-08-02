#include "Fixed.hpp"

const int Fixed::fracBit = 8;

std::ostream& operator<<(std::ostream& out,const Fixed& Fixed) {
	out << Fixed.toFloat();
	return out;
}

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	this->fixNumber = 0;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called\n";
	this->fixNumber = num << fracBit;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called\n";
	this->fixNumber = roundf(num * (1 << fracBit));
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
	// std::cout << "getRawBits member function called\n";
	return this->fixNumber;
}

void Fixed::setRawBits(int const raw) {
	this->fixNumber = raw;
}

float Fixed::toFloat( void ) const {
	return (float)this->fixNumber / (1 << fracBit);
}

int Fixed::toInt( void ) const {
	return this->fixNumber >> fracBit;
}
