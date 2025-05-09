/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:48:13 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/23 13:42:12 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) 
		this->
			_rawBits = other._rawBits;
	return *this;
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int intValue)
{
//	std::cout << "Int constructor called" << std::endl;
	_rawBits = intValue << _fractionalBits;
}

Fixed::Fixed(float floatValue)
{
//	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(floatValue * (1 << _fractionalBits));
}

float	Fixed::toFloat() const
{
	return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

int	Fixed::toInt() const
{
	return _rawBits >> _fractionalBits;
}

int	Fixed::getRawBits() const
{
	return _rawBits;
}

void	Fixed::setRawBits(int raw)
{
	_rawBits = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

bool	Fixed::operator>(const Fixed& other) const
{
	return _rawBits > other._rawBits;
}

bool	Fixed::operator<(const Fixed& other) const
{
	return _rawBits < other._rawBits;
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return _rawBits >= other._rawBits;
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return _rawBits <= other._rawBits;
}

bool	Fixed::operator==(const Fixed& other) const
{
	return _rawBits == other._rawBits;
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return _rawBits != other._rawBits;
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	if (other._rawBits == 0)
	{
		std::cerr << "Error:Division by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed&	Fixed::operator++()
{
	_rawBits++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	_rawBits++;
	return tmp;
}

Fixed&	Fixed::operator--()
{
	_rawBits--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	_rawBits--;
	return tmp;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}
