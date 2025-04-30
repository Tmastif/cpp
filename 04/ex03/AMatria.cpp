/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMatria.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:17:01 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/30 11:28:57 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    // AMateria(std::string const &type);
    // AMeteria(const AMateria &other);
    // AMateria &operator=(const AMateria &other);
    // virtual ~AMateria();

    #include "AMateria.hpp"

    AMateria::AMateria(std::string const &type) : _type(type)
    {
        std::cout << "AMateria cntr\n";
    }

    
    AMateria::AMateria(const AMateria &other)
    {
        
    }