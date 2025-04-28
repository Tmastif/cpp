/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:14:20 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/28 11:15:16 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

int     main(void)
{
    {
        Animal animal;
        std::cout << "class Animal - " << animal << std::endl;
        Animal dony(animal);
    }
    
    Dog dog;

    dog.makeSound();
    std::cout << "class Dog - " << dog << std::endl;

    Dog copydog(dog);
    return (0);
}