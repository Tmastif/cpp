/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:32 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/10 14:41:14 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <Harl.hpp>

void    Harl::complain(std::string level)
{
    int     nbr;
    
    FunctionMap complains[] = 
    {
        {"DEBUG",   1},
        {"INFO",    2},
        {"WARNING", 3},
        {"ERROR",   4}
    };

    for (int i = 0; i < 4; i++)
    {
        if (level == complains[i].level)
            nbr = complains[i].nbr;
    }

    switch (nbr)
    {
        case 1:
            std::cout << "[ DEBUG ]\ndebug debug debug DEBUG\n\n";
            /* fall through */ 
        case 2:
            std::cout << "[ INFO ]\ninfo INFO INFO info\n\n";
            /* fall through */ 
        case 3:
            std::cout << "[ WARNING ]\nWARNING warning WARNING warning\n\n";
            /* fall through */ 
        case 4:
            std::cout << "[ ERROR ]\nERROR ERROR ERROR ERROR\n\n";
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
}