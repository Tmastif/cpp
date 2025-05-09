/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:11:54 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/09 13:20:13 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"

Brain::Brain()
{
    arr_size = sizeof(ideas) / sizeof (ideas[0]);
    std::cout << "Brain constructor\n";
}

Brain::~Brain()
{
    std::cout << "Brain destructor\n";
}

Brain::Brain (const Brain &other)
{
    std::cout << "Brain copy cntr\n";
    arr_size = other.arr_size;
    
    for (int i = 0; i < arr_size; i++)
    {
        ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain &other)
{
    std::cout << "Brain copy assigment\n";
    if (this != &other)
    {
        arr_size = other.arr_size;
        
        for (int i = 0; i < arr_size; i++)
        {
            ideas[i] = other.ideas[i];
        }
    }
    return (*this);
}


std::string    Brain::getIdea(int nbr) const
{
    if (nbr >= 0 && nbr < arr_size)
    {
        return (ideas[nbr]);
    }
        return ("Invalid Range");        
}


void    Brain::setIdea(std::string idea, int nbr)
{
    if (nbr >= 0 && nbr < arr_size)
    {
        ideas[nbr] = idea;
    }
}

void    Brain::seeIdeas(void) const
{
    for (int i = 0; i < arr_size; i++)
    {
        if (ideas[i] != "")
            std::cout << i << ": " << ideas[i] << std::endl;
    }
}