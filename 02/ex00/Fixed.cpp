/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:13:11 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/25 15:03:00 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>
#include <iostream>
#include <ostream>


//Default constructor
Fixed::Fixed() : _width(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed& original)
{
    std::cout << "Copy constructor called" << std::endl;
    _width = original.getRawBits();
}

//Copy assignment
Fixed&   Fixed::operator=(const Fixed& original)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &original)
        _width = original.getRawBits();
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
    std::cout << "getRawBits member function called" << std::endl;
    return (_width);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _width = raw;
}
