/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:42:54 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/06 15:55:01 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"

// void        use(ICharacter& target);

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice cntr\n";
}

AMateria*   Ice::clone() const
{
    Ice *tmp = new Ice();
    return (tmp);
}

void        Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at "
    << target.getName() << " *\n";
}