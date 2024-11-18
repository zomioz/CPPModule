#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

# define R   "\x1B[31m"
# define G   "\x1B[32m"
# define Y   "\x1B[33m"
# define B_B "\x1B[0;36m"
# define B_R   "\x1B[1;31m"
# define B_G   "\x1B[1;32m"
# define B_Y   "\x1B[1;33m"
# define B_M  "\x1B[1;35m"
# define B_C  "\x1B[1;36m"
# define BOLD "\x1B[1m"
# define RESET "\x1B[0m"

class Fixed {
	private:
		int	_FixedPointValue;
		static const int _FractionnalBits;
	public:
		Fixed();
		Fixed (const Fixed &copy);
		Fixed (const int FixedPoint);
		Fixed (const float FixedPoint);
		~Fixed();
		//Operator
		Fixed &operator=(const Fixed &copy);
		bool operator>(const Fixed &second) const;
		bool operator<(const Fixed &second) const;
		bool operator>=(const Fixed &second) const;
		bool operator<=(const Fixed &second) const;
		bool operator==(const Fixed &second) const;
		bool operator!=(const Fixed &second) const;
		float operator+(const Fixed &second) const;
		float operator-(const Fixed &second) const;
		float operator*(const Fixed &second) const;
		float operator/(const Fixed &second) const;
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		//Function
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		static Fixed &min(Fixed &one, Fixed &two);
		static Fixed &max(Fixed &one, Fixed &two);
		static const Fixed &min(const Fixed &one, const Fixed &two);
		static const Fixed &max(const Fixed &one, const Fixed &two);
};

std::ostream	&operator<<(std::ostream &output, const Fixed &_Fixed);
#endif