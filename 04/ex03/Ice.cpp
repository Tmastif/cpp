/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:42:54 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/07 13:10:46 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"

// void        use(ICharacter& target);

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice cntr\n";
}

// Ice& Ice::operator=(const Ice &other)
// {
//     std::cout << "Ice copy assigment\n";
//     if (this != &other)
//         _type = other._type;
//     return (*this);
// }

AMateria*   Ice::clone() const
{
    return (new Ice(*this));
}

void        Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at "
    << target.getName() << " *\n";
}