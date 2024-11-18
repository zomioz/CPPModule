#include "Fixed.hpp"

const int Fixed::_FractionnalBits = 8;

Fixed::Fixed():_FixedPointValue(0)
{
	std::cout << B_G "Default constructor called" RESET << std::endl;
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

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << B_B "Surchage operator called" RESET << std::endl;
	this->_FixedPointValue = copy.getRawBits();
	return (*this);
}

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

int	Fixed::toInt(void) const
{
	return (this->_FixedPointValue >> this->_FractionnalBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_FixedPointValue / (float)(1 << this->_FractionnalBits));
}

std::ostream	&operator<<(std::ostream &output,Fixed const &_Fixed)
{
	output << _Fixed.toFloat();
	return (output);
}