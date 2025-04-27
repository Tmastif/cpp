/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:19:35 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/27 15:23:28 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"


//Default constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _name = name;
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    std::cout << "Frag constructor called" << std::endl;
}

//Destructor
FragTrap::~FragTrap()
{
    std::cout << "Frag destructor called" << std::endl;
}


//FUNCTIONS
void    FragTrap::attack(const std::string &target)
{
    if (_hit_points > 0 && _energy_points > 0)
    {
        std::cout << "FragTrap " << _name << " attacks " << 
        target << " causing " << _attack_damage << 
        " points of damage!\n";
        _energy_points--;
    }
    else
    {
        std::cout << "FragTrap " << _name << " can't attack " << 
        target << 
        ", it has not enough hit or energy points\n";
    }
}

void    FragTrap::highFiveGuys(void)
{
    std::cout << "FragTrap requests a high five!\n";
}
