/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:19:35 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/27 15:35:38 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"



//Default constructor
DiamondTrap::DiamondTrap(std::string name) 
: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    _name = name;
    ClapTrap::_name = name + "_clap_name";
    _hit_points = FragTrap::_hit_points;
    _energy_points = ScavTrap::_energy_points;
    _attack_damage = FragTrap::_attack_damage;
    std::cout << "Diamond constructor called" << std::endl;
}

//Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "Diamond destructor called" << std::endl;
}


//FUNCTIONS
void    DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "my name: " <<_name <<
    "\nmy ClapTrap's name: " << ClapTrap::_name << std::endl;
}
