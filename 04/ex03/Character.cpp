/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:27:22 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/08 17:17:07 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character(std::string name) : _name(name)
{
    std::cout << "Character cntr\n";
    for (int i = 0; i < _slots; i++)
        _inventory[i] = NULL;
}

Character::Character(void)
{
    std::cout << "Character cntr\n";
    _name = "default";
    for (int i = 0; i < _slots; i++)
    {
        _inventory[i] = NULL;
    }
}

Character::Character(const Character &other)
{
    std::cout << "Character copy cntr\n";
    _name = other._name;
    for (int i = 0; i < _slots; i++)
    {
        if (other._inventory[i] == NULL)
            _inventory[i] = NULL;
        else
            _inventory[i] = other._inventory[i]->clone();
    }
}

Character& Character::operator=(const Character &other)
{
    std::cout << "Character copy assigment\n";
    if (this != &other)
    {
        _name = other._name;
        this->deleteInventory();
        for (int i = 0; i < _slots; i++)
        {
            if (other._inventory[i] == NULL)
                _inventory[i] = NULL;
            else
                _inventory[i] = other._inventory[i]->clone();
        }
    }
    return (*this);
}

Character::~Character(void)
{
    std::cout << "Character destructor\n";
    this->deleteInventory();
}

//FUNCTIONS

void Character::deleteInventory(void)
{
    for (int i = 0; i < _slots; i++)
    {
        if (_inventory[i] != NULL)
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
}

std::string const &Character::getName(void) const
{
    return (_name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < _slots; i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            return ;
        }
    }
    std::cout << "Inventory full\n";
}

void Character::unequip(int idx)
{
    if (idx < _slots && idx >=0)
    {
        if (_inventory[idx] == NULL)
            std::cout << "Inventory slot " << idx << " is empty\n";
        _inventory[idx] = NULL;
        return ;
    }
    std::cout << "index is out of inventory range\n";
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < _slots && idx >=0)
    {
        if (_inventory[idx] != NULL)
            _inventory[idx]->use(target);
        else
            std::cout << "inventory is empty at slot " << idx <<"\n";
        return ;
    }
    std::cout << "index is out of inventory range\n";
}