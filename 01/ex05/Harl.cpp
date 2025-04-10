/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:32 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/10 14:19:22 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <Harl.hpp>

void    Harl::debug(void)
{
    std::cout << "debug debug debug DEBUG\n";
};

void    Harl::info(void)
{
    std::cout << "info INFO INFO info\n";
};

void    Harl::warning(void)
{
    std::cout << "WARNING warning WARNING warning\n";
};
void    Harl::error(void)
{
    std::cout << "ERROR ERROR ERROR ERROR\n";
};

void    Harl::complain(std::string level)
{
    FunctionMap complains[] = 
    {
        {"debug", &Harl::debug},
        {"info", &Harl::info},
        {"warning", &Harl::warning},
        {"error", &Harl::error}
    };

    for (int i = 0; i < 4; i++)
    {
        if (level == complains[i].level)
        {
            (this->*complains[i].funcPtr)();
            return ;
        }
    }
    std::cout << "No appropriate level found\n";
}