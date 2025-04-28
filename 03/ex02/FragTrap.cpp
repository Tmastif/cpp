/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:19:35 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/28 11:31:51 by ilazar           ###   ########.fr       */
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

//Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "Frag copy constructor called" << std::endl;
    _name = other._name;
    _hit_points = other._hit_points;
    _energy_points = other._energy_points;
    _attack_damage = other._attack_damage;
}

//Assigment Constructor
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "Frag copy assignment operator called" << std::endl;
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
