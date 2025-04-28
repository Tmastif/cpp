/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:14:41 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/28 12:12:12 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    _type = other._type;
    std::cout << "WrongAnimal copy constructor\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy assigment operator\n";
    if (this != &other)
        _type = other._type;
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor\n";
}

std::string     WrongAnimal::getType(void) const
{
    return (_type);
}

//Representation
std::ostream& operator<<(std::ostream& os, const WrongAnimal& animal)
{
    os << "My type is: " << animal.getType();
    return os;
}
