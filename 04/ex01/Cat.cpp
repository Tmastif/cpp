/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:55:39 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/29 18:17:32 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    _type = "Cat";
    brain = new Brain();
    std::cout << "Cat cntr\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy cntr\n";
    _type = other._type;
    brain = NULL;
    if (other.brain != NULL)
        brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assigment\n";
    if (this != &other)
    {
        _type = other._type;
        delete brain;
        brain = NULL;
        if (other.brain != NULL)
            brain = new Brain(*other.brain);
    }
    return (*this);
}


Cat::~Cat(void)
{
    delete brain;
    std::cout << "Cat destructor\n";
}

void    Cat::makeSound(void) const
{
    std::cout << "Cat sound! Miau Miau\n";
}


void    Cat::setIdea(std::string idea, int nbr)
{
    brain->setIdea(idea, nbr);
}

void    Cat::seeIdeas(void) const
{
    brain->seeIdeas();
}