/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:18:26 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/25 16:44:28 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>
#include <iostream>

int main(void)
{
    // std::string dino = "Dino";
    ClapTrap a("Dino");
    
    
    a.attack("Zauer");
    a.takeDamage(5);
    a.beRepaired(10);
    
    a.takeDamage(20);
    
    a.attack("Zauer");
    a.beRepaired(10);
    a.takeDamage(20);
    
    return (0);
}