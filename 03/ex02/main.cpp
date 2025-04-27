/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:18:26 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/27 14:23:07 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap a("Parent");
    ScavTrap b("Scav_Child");
    FragTrap c("Frag_child");
    
    a.attack("Sauer");
    a.takeDamage(5);
    a.beRepaired(10);
    a.takeDamage(20);
    
    b.attack("Sauer");
    b.takeDamage(100);
    b.attack("Sauer");
    b.guardGate();
    
    c.attack("enemy");
    c.takeDamage(150);
    c.beRepaired(20);
    c.highFiveGuys();
    
    return (0);
}