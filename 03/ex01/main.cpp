/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:18:26 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/28 11:27:41 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    {
        std::cout << "#######copy constructor test\n";
        ScavTrap bb(b);
    }
    std::cout << "#######\n";
    
    ClapTrap a("Parent");
    ScavTrap b("Child");

    
    a.attack("Sauer");
    a.takeDamage(5);
    a.beRepaired(10);
    
    a.takeDamage(20);
    
    a.attack("Sauer");
    a.beRepaired(10);
    a.takeDamage(20);
    
    b.attack("Sauer");
    b.takeDamage(100);
    b.attack("Sauer");
    b.guardGate();
    
    return (0);
}