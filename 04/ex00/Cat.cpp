/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:55:39 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/28 12:06:34 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    _type = "Cat";
    std::cout << "Cat cntr\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy cntr\n";
    _type = other._type;
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assigment\n";
    if (this != &other)
        _type = other._type;
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor\n";
}

void    Cat::makeSound(void) const
{
    std::cout << "Cat sound! Miau Miau\n";
}