/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:14:41 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/29 17:02:44 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal(void) : _type("Animal")
{
    std::cout << "Animal constructor\n";
}

Animal::Animal(const Animal &other)
{
    _type = other._type;
    std::cout << "Animal copy constructor\n";
}

Animal& Animal::operator=(const Animal &other)
{
    std::cout << "Animal copy assigment operator\n";
    if (this != &other)
        _type = other._type;
    return (*this);
}


Animal::~Animal(void)
{
    std::cout << "Animal destructor\n";
}

std::string     Animal::getType(void) const
{
    return (_type);
}

//Representation
std::ostream& operator<<(std::ostream& os, const Animal& animal)
{
    os << "My type is: " << animal.getType();
    return os;
}


void    Animal::setIdea(std::string idea, int nbr)
{
    (void) idea;
    (void) nbr;
}
