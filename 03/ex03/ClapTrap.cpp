/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:19:35 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/28 11:43:57 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ClapTrap.hpp>


//Default constructor
ClapTrap::ClapTrap(std::string name)
{
    _name = name;
    _hit_points = 10;
    _energy_points = 10;
    _attack_damage = 0;
    std::cout << "Clap constructor called" << std::endl;
}

//Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Clap copy constructor called" << std::endl;
    _name = other._name;
    _hit_points = other._hit_points;
    _energy_points = other._energy_points;
    _attack_damage = other._attack_damage;
}

//Assigment Constructor
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
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
ClapTrap::~ClapTrap()
{
    std::cout << "Clap destructor called" << std::endl;
}


//FUNCTIONS
void    ClapTrap::attack(const std::string &target)
{
    if (_hit_points > 0 && _energy_points > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << 
        target << " causing " << _attack_damage << 
        " points of damage!\n";
        _energy_points--;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " can't attack " << 
        target << 
        ", it has not enough hit or energy points\n";
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_hit_points > 0)
    {
        std::cout << "ClapTrap " << _name << " takes " << 
            amount << " points of damage!\n";
        _hit_points -= (int)amount;
        if (_hit_points < 0)
            _hit_points = 0;
    }
    else
    {
         std::cout << "ClapTrap " << _name << 
         " can't take more damage, he is already dead :/\n";
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
   if (_hit_points > 0 && _energy_points > 0)
   {
        std::cout << "ClapTrap " << _name << 
        " gained " << amount << " hit points!\n";
        _hit_points += (int)amount;
        _energy_points--;
   }
   else
   {
       std::cout << "ClapTrap " << _name << 
       " can't repair itself it has not enough hit or energy points\n";
   }
}
