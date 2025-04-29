/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:42:49 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/29 18:17:52 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    _type = "Dog";
    brain = new Brain();
    std::cout << "Dog constructor\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor\n";
    _type = other._type;
    brain = NULL;
    if (other.brain != NULL)
        brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assigment\n";
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

Dog::~Dog(void)
{
    delete brain;
    std::cout << "Dog destructor\n";
}

void    Dog::makeSound(void) const
{
    std::cout << "Dog sound! haw haw" << std::endl;
}

void    Dog::setIdea(std::string idea, int nbr)
{
    brain->setIdea(idea, nbr);
}

void    Dog::seeIdeas(void) const
{
    brain->seeIdeas();
}