/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:42:58 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/08 18:19:05 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void    test_inventory(void);
void    test_copy(void);
void    test_assigment(void);
void    test_materiaSource(void);

int main(void)
{
    //MY TESTS
    // test_inventory();
    // test_copy();
    // test_assigment();
    // test_materiaSource();

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    
    return (0);
}

void    test_inventory(void)
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

    //enquiping slot 0 and deleting it manualy
    louis->unequip(0);
    delete ice2;
    
    louis->use(3, *donny);
    donny->use(1, *louis);
    
    delete donny;
    delete louis;
}

void    test_copy(void)
{
    std::cout << "##copy cntr:##\n";
    std::cout << "#creating donny:\n";
    Character *donny = new Character("donny");
    std::cout << "#creating Ice:\n";
    AMateria *ice = new Ice();
    std::cout << "#equiping donny with ice\n";
    donny->equip(ice);
    std::cout << "#copying donny:\n";
    Character *donny_copy = new Character(*donny);
    std::cout << "#deleting original donny:\n";
    delete donny;
    std::cout << "#still able to use ice from deep copied donny:\n";
    donny_copy->use(0, *donny_copy);
    delete donny_copy;
}

void    test_assigment(void)
{
    std::cout << "##copy assigment:##\n";
    std::cout << "#creating donny:\n";
    Character *donny = new Character("donny");
    std::cout << "#creating bob:\n";
    Character *bob = new Character("bob");
    std::cout << "#creating Ice:\n";
    AMateria *ice = new Ice();
    std::cout << "#equiping donny with ice\n";
    donny->equip(ice);
    std::cout << "#assigning bob = donny:\n";
    *bob = *donny;
    std::cout << "#deleting donny:\n";
    delete donny;
    std::cout << "#still able to use ice from deep copied bob:\n";
    bob->use(0, *bob);
    delete bob;
}

void    test_materiaSource(void)
{
    std::cout << "##MateriaSource:##\n";
    
    MateriaSource *source = new MateriaSource();
    std::cout << "#creating and teaching type cure:\n";
    AMateria *cure = new Cure();
    source->learnMateria(cure);
    std::cout << "#creating a new cure from templates:\n";
    AMateria *cure2 = source->createMateria("cure");
    std::cout << "#deleting it:\n";
    delete cure2;
    std::cout << "#trying to create type that doesn't exists:\n";
    source->createMateria("ice");
    std::cout << "#clean delete:\n";
    delete source;
}