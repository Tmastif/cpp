/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:14:20 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/09 13:18:51 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int     main(void)
{
    const Animal* meta = new Animal();
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << "#cat sound:\n";
    i->makeSound();
    std::cout << "#dog sound:\n";
    j->makeSound();
    std::cout << "#Meta animal sound: (no sound)\n";
    meta->makeSound();
    std::cout << "#Meta wrong animal sound:\n";
    wrongMeta->makeSound();
    std::cout << "#wrong cat made of wrong animal - Wrong animal sound:\n";
    wrongCat->makeSound();
    const WrongCat* wCat = new WrongCat();
    std::cout << "#wrong cat made out of wrong cat - Wrong cat sound:\n";
    wCat->makeSound();
    
    std::cout << "\n##MY TESTS##\n";
    {
        Animal animal;
        std::cout << "class Animal - " << animal << std::endl;
    }
    std::cout << "###########\n";
    {    
        std::cout << "\nDog:" << std::endl;
        Dog dog;

        std::cout << "class Dog - " << dog << std::endl;
        dog.makeSound();

        {
            std::cout << "##copy cntr check##\n";
            Dog copydog(dog);
            copydog.makeSound();
        }
        std::cout << "####\n";
    }
    std::cout << "###########\n";
    {
        std::cout << "\nCat:" << std::endl;
        Cat cat;
        std::cout << "class Cat - " << cat << std::endl;
        cat.makeSound();
    }
    return (0);
}