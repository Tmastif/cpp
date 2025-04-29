/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:14:41 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/29 18:19:29 by ilazar           ###   ########.fr       */
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
        
        virtual void    makeSound() const {};
        std::string     getType() const;
        virtual void    setIdea(std::string idea, int nbr);
        virtual void    seeIdeas() const {};
};

std::ostream& operator<<(std::ostream& os, const Animal &animal);

/* the destructor is now virtual
to ensure that when a derived class is deleted through a Animal* pointer
the derived class destructor will be called first, folllowed by the base destructor
*/

#endif