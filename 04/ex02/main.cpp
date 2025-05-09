/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:14:20 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/09 13:37:12 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

void    testBrainClass(void);
void    testAnimalArray(void);
void    testDeepCopy(std::string which);

int     main(void)
{
    // testBrainClass();
    // testAnimalArray();
    // testDeepCopy("dog");
    // testDeepCopy("cat");

    Dog dog;
    Cat cat;
    
    dog.makeSound();
    cat.makeSound();
    
    // Animal animal;
    

    return (0);
}

void       testBrainClass(void)
{
    std::cout << "##checking Brain class##\n\n";
    {
        Brain first_brain;

        first_brain.setIdea("set the world on fire\n", 0);
        std::cout << "1st brain idea: " << first_brain.getIdea(0);
        Brain seconed_brain (first_brain);
        //seconed brain should now contain all of the first's ideas
        std::cout << "2nd brain idea: " << seconed_brain.getIdea(0);
        
        std::cout << "###\n";
        first_brain.setIdea("learn greek\n", 1);
        first_brain.setIdea("invent another brain\n", 2);
        
        std::cout << "2nd brain idea: should be empty\n" << seconed_brain.getIdea(1);
        seconed_brain = first_brain;
        //2nd brain should contain all the first's ideas
        std::cout << "2nd brain idea: " << seconed_brain.getIdea(1);
        std::cout << "2nd brain idea: " << seconed_brain.getIdea(2);
    }
}


void    testAnimalArray(void)
{
    std::cout << "\n##checking Animals Array##\n\n";
    {
        int arr_size = 10;
        Animal *animals[arr_size];
        int i;
        
        for (i = 0; i < arr_size / 2; i++)
        {
            animals[i] = new Dog();
        }
        for (; i < arr_size; i++)
        {
            animals[i] = new Cat();
        }
        std::cout << "\n\nThe array is half dogs half cats:\n";
        for (i = 0; i < arr_size; i++)
            std::cout << i << ": " << animals[i]->getType() << std::endl;
        
        std::cout << "\n\n";
        for (i = 0; i < arr_size; i++)
            delete animals[i];
    }
}

void    testDeepCopy(std::string which)
{
    std::cout << "##Test deep copy:##\n";
    if (which == "dog")
    {
        Dog dog;
         
        dog.setIdea("scratch", 0);
        dog.setIdea("chase squirrl", 1);
        dog.setIdea("steal food", 2);
        dog.seeIdeas();
        {
            Dog seconed(dog);
            seconed.seeIdeas();
        }
        std::cout << "\n";
        {
            Dog seconed;
            seconed = dog;
            seconed.seeIdeas();
        }
        std::cout << "\n";
    }
    else if (which == "cat")
    {
        Cat cat;
        cat.setIdea("scratch", 0);
        cat.setIdea("chase squirrl", 1);
        cat.setIdea("steal food", 2);
        cat.seeIdeas();
        {
            Cat seconed(cat);
            seconed.seeIdeas();
        }
        std::cout << "\n";
        {
            Cat seconed;
            seconed = cat;
            seconed.seeIdeas();
        }
        std::cout << "\n";
    }
}