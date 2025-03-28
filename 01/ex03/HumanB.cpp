/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:19:46 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/28 10:15:22 by ilazar           ###   ########.fr       */
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
//will take a ref to match the main requirments
//it means the function must recieve a valid weapon and not a null
void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon; //(pointer to referance)
}

void    HumanB::attack(void)
{
    std::cout << this->name << " attacks with their " \
    << this->weapon->getType() << std::endl;
}