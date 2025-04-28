/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:14:20 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/28 12:21:39 by ilazar           ###   ########.fr       */
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
    // const WrongAnimal* meta = new WrongAnimal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    // const WrongAnimal* i = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    //MY TESTS
    // {
    //     Animal animal;
    //     std::cout << "class Animal - " << animal << std::endl;
    // }
    // std::cout << "###########\n";
    // {    
    //     std::cout << "\nDog:" << std::endl;
    //     Dog dog;

    //     std::cout << "class Dog - " << dog << std::endl;
    //     dog.makeSound();

    //     {
    //         std::cout << "##copy cntr check##\n";
    //         Dog copydog(dog);
    //         copydog.makeSound();
    //     }
    //     std::cout << "####\n";
    // }
    // std::cout << "###########\n";
    // {
    //     std::cout << "\nCat:" << std::endl;
    //     Cat cat;
    //     std::cout << "class Cat - " << cat << std::endl;
    //     cat.makeSound();
    // }
    return (0);
}