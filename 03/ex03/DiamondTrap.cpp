/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:19:35 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/08 12:37:05 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"



//Default constructor
DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clapTrap"), FragTrap(name), ScavTrap(name)
{
    _name = name;
    ClapTrap::_name = name + "_clap_name";
    _hit_points = FragTrap::_hit_points;
    _energy_points = ScavTrap::_energy_points;
    _attack_damage = FragTrap::_attack_damage;
    std::cout << "Diamond constructor called" << std::endl;
}
//Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
: ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    std::cout << "Diamond copy constructor called" << std::endl;
    _name = other._name;
    _hit_points = other._hit_points;
    _energy_points = other._energy_points;
    _attack_damage = other._attack_damage;
}

//Assigment Constructor
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "Diamond copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hit_points = other._hit_points;
        _energy_points = other._energy_points;
        _attack_damage = other._attack_damage;
    }
    return (*this);
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

void    DiamondTrap::highFiveGuys(void)
{
    std::cout << "DiamondTrap requests a high five!\n";
}

void    DiamondTrap::guardGate(void)
{
    std::cout << "DiamondTrap is now in Gate keeper mode\n";
}