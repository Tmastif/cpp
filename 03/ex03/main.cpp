/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:18:26 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/28 11:44:44 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
    // ScavTrap b("Scav_Child");
    // FragTrap c("Frag_child");
    
    DiamondTrap d("Diamond");
    // d.attack("you");
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