/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:18:26 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/11 18:49:25 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>
#include <iostream>

int main(void)
{
    ClapTrap a("Dino");
    
    
    a.attack("Sauer");
    a.takeDamage(5);
    a.beRepaired(10);
    
    a.takeDamage(20);
    
    a.attack("Sauer");
    a.beRepaired(10);
    a.takeDamage(20);
    
    return (0);
}