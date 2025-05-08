/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:07:44 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/08 14:10:56 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    
protected:
    std::string _type;
    
public:
    AMateria(std::string const &type);
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);
    virtual ~AMateria();
    
    std::string const &getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter &target) { (void)target; };

};

#endif