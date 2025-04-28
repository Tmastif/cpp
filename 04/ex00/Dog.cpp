/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:42:49 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/28 11:19:59 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    _type = "Dog";
    std::cout << "Dog constructor\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor\n";
    _type = other._type;
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assigment\n";
    if (this != &other)
        _type = other._type;
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor\n";
}