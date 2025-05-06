/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:18:26 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/29 13:18:13 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    
    ClapTrap a("Parent");
    ScavTrap b("Child");
    
    {
    std::cout << "#######copy constructor test\n";
        ScavTrap bb(b);
    }
    std::cout << "#######\n";
    
    a.attack("enemy");
    b.attack("enemy");
    b.beRepaired(20);
    b.takeDamage(100);
    b.attack("Sauer");
    b.guardGate();

    return (0);
}