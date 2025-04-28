/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:19:35 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/28 11:33:11 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"


//Default constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _name = name;
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << "Scav constructor called" << std::endl;
}

//Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "Scav copy constructor called" << std::endl;
    _name = other._name;
    _hit_points = other._hit_points;
    _energy_points = other._energy_points;
    _attack_damage = other._attack_damage;
}

//Assigment Constructor
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "Scav copy assignment operator called" << std::endl;
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
ScavTrap::~ScavTrap()
{
    std::cout << "Scav destructor called" << std::endl;
}


//FUNCTIONS
void    ScavTrap::attack(const std::string &target)
{
    if (_hit_points > 0 && _energy_points > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << 
        target << " causing " << _attack_damage << 
        " points of damage!\n";
        _energy_points--;
    }
    else
    {
        std::cout << "ScavTrap " << _name << " can't attack " << 
        target << 
        ", it has not enough hit or energy points\n";
    }
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap is now in Gate keeper mode\n";
}
