/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:18:26 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/29 13:24:12 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{

    {
        std::cout << "#####Frag created:\n";
        FragTrap c("Frag_child");
        std::cout << "#####Frag deleted:\n";
    }
    std::cout << "\n";
    {
        ClapTrap a("Parent");
        ScavTrap b("Scav_Child");
    
        std::cout << "\n";
        a.attack("Sauer");
        a.takeDamage(20);
        std::cout << "\n";
        b.attack("Sauer");
        b.guardGate();
    }
    std::cout << "\n";
    FragTrap c("Frag_child");
    c.attack("enemy");
    c.highFiveGuys();
    
    return (0);
}