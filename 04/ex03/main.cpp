/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:42:58 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/08 15:21:25 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main(void)
{
    AMateria *ice1 = new Ice();
    AMateria *ice2 = new Ice();
    AMateria *ice3 = new Ice();
    AMateria *ice4 = new Ice();
    AMateria *cure1 = new Cure();
    AMateria *cure2 = new Cure();
    Character *donny = new Character("donny");
    Character *louis = new Character("louis");

    
    donny->equip(ice1);
    donny->equip(cure2);
    donny->use(0, *louis);
    louis->equip(ice2);
    louis->use(0, *donny);
    louis->equip(ice3);
    louis->equip(ice4);
    louis->equip(cure1);
    std::cout << "#equiping more than inventory capacity:\n";
    louis->equip(cure1);
    std::cout << "#using index out of range:\n";
    louis->use(4, *donny);
    std::cout << "#using index number 3:\n";
    louis->use(3, *donny);


    louis->use(3, *donny);
    donny->use(1, *louis);
    donny->deleteInventory();
    louis->deleteInventory();
    
    delete donny;
    delete louis;
    
    return (0);
}