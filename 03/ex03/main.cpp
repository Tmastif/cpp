/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:18:26 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/29 13:27:32 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
    
    DiamondTrap d("Diamond");
    d.attack("us");
    d.highFiveGuys();
    d.guardGate();
    d.whoAmI();
    
    std::cout << "####copy constructor check:\n";
    {
        DiamondTrap dd(d);
    }
    std::cout << "####\n";
    
    // b.attack("Sauer");
    // b.takeDamage(100);
    // b.guardGate();
    
    // c.attack("enemy");
    // c.takeDamage(150);
    // c.highFiveGuys();
    
    return (0);
}