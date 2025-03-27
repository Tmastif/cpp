/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:19:46 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/27 11:57:28 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <Weapon.hpp>
#include <HumanB.hpp>


HumanB::HumanB(std::string name)
{
    this->name = name;
}

void    HumanB::setWeapon(Weapon weapon)
{
    this->weapon = weapon;      
}

void    HumanB::attack(void)
{
    std::cout << this->name << " attacks with their " \
    << this->weapon.getType() << std::endl;
}