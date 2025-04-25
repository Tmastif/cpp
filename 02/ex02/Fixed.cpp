/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:13:11 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/25 14:25:29 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>
#include <iostream>
#include <ostream>
#include <cmath>


//Default constractor
Fixed::Fixed() : _width(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

//Int constractor
Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    _width = value << _bits;
}

//Float constructor
Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
    _width = static_cast<int>(roundf(value * (1 << _bits)));
}

//Copy constractor
Fixed::Fixed(const Fixed& original)
{
    // std::cout << "Copy constructor called" << std::endl;
    _width = original.getRawBits();
}

//Copy assignment
Fixed&   Fixed::operator=(const Fixed& original)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &original)
        _width = original.getRawBits();
    return *this;
}

//Destructor
Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}



//FUNCTIONS

int     Fixed::getRawBits() const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (_width);
}

void    Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    _width = raw;
}

//int convertor
int     Fixed::toInt(void) const
{
    return (_width >> _bits);
}

//Float convertor
float   Fixed::toFloat(void) const
{
    return (static_cast<float>(_width) / (1 << _bits));
}

//Representation
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    // os << fixed.toFloat();
    return (os << fixed.toFloat());
}


//Comparison
bool Fixed::operator>(const Fixed& other) const
{
    return (this->_width > other._width);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->_width < other._width);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->_width >= other._width);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->_width <= other._width);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->_width == other._width);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->_width != other._width);
}


//Arithmetic
Fixed	Fixed::operator+(Fixed const &other) const
{
	Fixed	result(this->toFloat() + other.toFloat());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	Fixed	result(this->toFloat() - other.toFloat());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &other) const
{
	Fixed	result(this->toFloat() * other.toFloat());
	return (result);
}

Fixed	Fixed::operator/(Fixed const &other) const
{
	Fixed	result(this->toFloat() / other.toFloat());
	return (result);
}

//prefix    ++obj
Fixed& Fixed::operator++()
{
    _width += 1;
    return *this;
}

Fixed& Fixed::operator--()
{
    _width -= 1;
    return *this;
}

//postfix   obj++ create a copy to be able to return original value
Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _width += 1;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _width -= 1;
    return temp;
}

// Non-const min/max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

// Const min/max
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}