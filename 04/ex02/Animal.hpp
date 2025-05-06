/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:14:41 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/30 11:05:15 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string _type;
    
    public:
        Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();
        
        virtual void    makeSound() const = 0;
        std::string     getType() const;
        virtual void    setIdea(std::string idea, int nbr);
        virtual void    seeIdeas() const {};
};

std::ostream& operator<<(std::ostream& os, const Animal &animal);

/*
the function makeSound is now a pure virtual function
and so the class becomes abstract and cannot be instantiate
*/

#endif