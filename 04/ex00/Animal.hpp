/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:14:41 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/28 11:16:35 by ilazar           ###   ########.fr       */
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
        ~Animal();
        
        virtual void    makeSound() const {};
        std::string getType() const;
        // void    whatsMyType();
};

std::ostream& operator<<(std::ostream& os, const Animal &animal);

//make sound is an empty virtual function.
//Derived classes may optionally override it.

#endif