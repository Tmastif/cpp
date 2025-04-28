/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:55:39 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/28 12:15:39 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    _type = "WrongCat";
    std::cout << "WrongCat cntr\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy cntr\n";
    _type = other._type;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat copy assigment\n";
    if (this != &other)
        _type = other._type;
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor\n";
}

void    WrongCat::makeSound(void) const
{
    std::cout << "WrongCat sound! WrongMiau WrongMiau\n";
}