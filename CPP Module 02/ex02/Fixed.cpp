#include "Fixed.hpp"

const int Fixed::_FractionnalBits = 8;

Fixed::Fixed():_FixedPointValue(0)
{
	std::cout << B_G "Default constructor calles" RESET << std::endl;
}

Fixed::Fixed (const Fixed &copy)
{
	std::cout << B_G "Copy constructor called" RESET << std::endl;
	*this = copy;
}

Fixed::Fixed (const int FixedPoint):_FixedPointValue(FixedPoint << Fixed::_FractionnalBits)
{
	std::cout << B_G "INT constructor called" RESET << std::endl;
}

Fixed::Fixed (const float FixedPoint):_FixedPointValue(roundf(FixedPoint * (1 << Fixed::_FractionnalBits)))
{
	std::cout << B_G "FLOAT constructor called" RESET << std::endl;
}

Fixed::~Fixed()
{
	std::cout << B_R "Destructor called" RESET << std::endl;
}

//SETTER & GETTER

int	Fixed::getRawBits(void) const
{
	std::cout << B_M "getRawBits member function called" RESET << std::endl;
	return (this->_FixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << B_M "setRawBits member function called" RESET << std::endl;
	this->_FixedPointValue = raw;
}

//FUNCTION

int	Fixed::toInt(void) const
{
	return (this->_FixedPointValue >> this->_FractionnalBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_FixedPointValue / (float)(1 << this->_FractionnalBits));
}

//OPERATOR

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << B_B "Surchage operator called" RESET << std::endl;
	this->_FixedPointValue = copy.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &output,Fixed const &_Fixed)
{
	output << _Fixed.toFloat();
	return (output);
}

bool	Fixed::operator>(const Fixed &second) const
{
	return (this->toFloat() > second.toFloat());
}

bool	Fixed::operator<(const Fixed &second) const
{
	return (this->toFloat() < second.toFloat());
}

bool	Fixed::operator>=(const Fixed &second) const
{
	return (this->toFloat() >= second.toFloat());
}

bool	Fixed::operator<=(const Fixed &second) const
{
	return (this->toFloat() <= second.toFloat());
}

bool	Fixed::operator==(const Fixed &second) const
{
	return (this->toFloat() == second.toFloat());
}

bool	Fixed::operator!=(const Fixed &second) const
{
	return (this->toFloat() != second.toFloat());
}

float	Fixed::operator+(const Fixed &second) const
{
	return (this->toFloat() + second.toFloat());
}

float	Fixed::operator-(const Fixed &second) const
{
	return (this->toFloat() - second.toFloat());
}

float	Fixed::operator*(const Fixed &second) const
{
	return (this->toFloat() * second.toFloat());
}

float Fixed::operator/(const Fixed &second) const
{
	if (second._FixedPointValue == 0)
	{
		std::cout << B_R "Error: Division by zero." RESET << std::endl;
		return (0);
	}
	return (this->toFloat() / second.toFloat());
}

Fixed &Fixed::operator++()
{
	this->_FixedPointValue++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->_FixedPointValue--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tempo = *this;
	this->_FixedPointValue++;
	return (tempo);
}

Fixed Fixed::operator--(int)
{
	Fixed tempo = *this;
	this->_FixedPointValue--;
	return (tempo);
}

Fixed &Fixed::min(Fixed &one, Fixed &two)
{
	if (one < two)
		return (one);
	return (two);
}

const Fixed &Fixed::min(const Fixed &one, const Fixed &two)
{
	if (one < two)
		return (one);
	return (two);
}

Fixed &Fixed::max(Fixed &one, Fixed &two)
{
	if (one > two)
		return (one);
	return (two);
}

const Fixed &Fixed::max(const Fixed &one, const Fixed &two)
{
	if (one > two)
		return (one);
	return (two);
}