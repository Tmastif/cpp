/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:42:54 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/08 15:20:58 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"

Cure::Cure() : AMateria("ice")
{
    std::cout << "Cure cntr\n";
}

Cure::Cure(const Cure &other) : AMateria(other)
{
    std::cout << "Cure copy cntr\n";
}

Cure& Cure::operator=(const Cure &other)
{
    std::cout << "Cure copy assigment\n";
    if (this != &other)
        AMateria::operator=(other);
    return (*this);
}

Cure::~Cure(void)
{
    std::cout << "Cure destructor\n";
}

AMateria*   Cure::clone() const
{
    return (new Cure(*this));
}

void        Cure::use(ICharacter& target)
{
    std::cout << "* heals "
    << target.getName() << "'s wounds *\n";
}