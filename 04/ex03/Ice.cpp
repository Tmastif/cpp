/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:42:54 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/08 15:13:59 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice cntr\n";
}

Ice::Ice(const Ice &other) : AMateria(other)
{
    std::cout << "Ice copy cntr\n";
}

Ice& Ice::operator=(const Ice &other)
{
    std::cout << "Ice copy assigment\n";
    if (this != &other)
        AMateria::operator=(other);
    return (*this);
}

Ice::~Ice(void)
{
    std::cout << "Ice destructor\n";
}

AMateria*   Ice::clone() const
{
    return (new Ice(*this));
}

void        Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at "
    << target.getName() << " *\n";
}