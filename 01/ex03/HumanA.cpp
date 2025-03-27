/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:19:46 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/27 11:52:58 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <Weapon.hpp>
#include <HumanA.hpp>


HumanA::HumanA(std::string name, Weapon weapon)
{
    this->name = name;
    this->weapon = weapon;
}

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " \
    << this->weapon.getType() << std::endl;
}