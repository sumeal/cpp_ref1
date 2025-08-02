#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed& other);
	Fixed operator+(const Fixed& num) const;
	Fixed operator-(const Fixed& num) const;
	Fixed operator*(const Fixed& num) const;
	Fixed operator/(const Fixed& num) const;
	bool operator<(const Fixed& num) const;
	bool operator>(const Fixed& num) const;
	bool operator>=(const Fixed& num) const;
	bool operator<=(const Fixed& num) const;
	bool operator==(const Fixed& num) const;
	bool operator!=(const Fixed& num) const;
	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
private:
	int fixNumber;
	static const int fracBit;
};

std::ostream& operator<<(std::ostream& out, const Fixed& Fixed);

#endif