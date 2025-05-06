/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:40:10 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/30 11:03:56 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;
    
    public:
        Dog();
        Dog(const Dog &other);
        Dog& operator=(const Dog &other);
        ~Dog();
        
        void          makeSound() const;
        void          setIdea(std::string idea, int nbr);
        void          seeIdeas() const;
        
};

#endif