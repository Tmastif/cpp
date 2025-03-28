/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:19:07 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/28 10:13:09 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Weapon.hpp>
#include <HumanA.hpp>
#include <HumanB.hpp>

int     main(void)
{
    // HumanA use a reference to Weapon.
    // he is always armed, meaning it will always have a Weapon.
    // A reference cannot be null and must be initialized at construction.
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }

    // HumanB use a pointer to Weapon.
    // HumanB may not always have a weapon.
    // A pointer can be null, representing the absence of a weapon.
    // therefor he could be unarmed and change weapons later.
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return (0);
}
