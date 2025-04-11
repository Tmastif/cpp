/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:13:11 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/11 18:29:23 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>
#include <iostream>
#include <ostream>
#include <cmath>


//Default constractor
Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//Int constractor
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = value << fractional_bits;
}

//Float constructor
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = static_cast<int>(roundf(value * (1 << fractional_bits)));
}

//Copy constractor
Fixed::Fixed(const Fixed& original)
{
    std::cout << "Copy constructor called" << std::endl;
    value = original.getRawBits();
}

//Copy assignment
Fixed&   Fixed::operator=(const Fixed& original)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = original.getRawBits();
    return *this;
}

//Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}



//FUNCTIONS

int     Fixed::getRawBits() const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void    Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

//int convertor
int     Fixed::toInt(void) const
{
    return (value >> fractional_bits);
}

//Float convertor
float   Fixed::toFloat(void) const
{
    return (static_cast<float>(value) / (1 << fractional_bits));
}


//Representation
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}