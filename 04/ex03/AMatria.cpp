/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMatria.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:17:01 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/06 15:39:38 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    #include "AMateria.hpp"

    AMateria::AMateria(std::string const &type) : _type(type)
    {
        std::cout << "AMateria cntr\n";
    }
    
    AMateria::AMateria(const AMateria &other)
    {
        std::cout << "AMateria copy cntr\n";
        _type = other._type;
    }

    AMateria& AMateria::operator=(const AMateria &other)
    {
        std::cout << "AMateria copy assigment\n";
        if (this != &other)
            _type = other._type;
        return (*this);
    }

    AMateria::~AMateria(void)
    {
        std::cout << "AMateria destructor\n";
    }

    
    //FUNCTIONS
    std::string const& AMateria::getType(void) const
    {
        return (_type);
    }