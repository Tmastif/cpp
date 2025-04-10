/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:50:29 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/10 14:18:02 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>
#include <string>
#include <iostream>

int     main(void)
{
    Harl harl;
    std::string input;

    harl.complain("debug");
    harl.complain("info");
    harl.complain("warning");
    harl.complain("error");

    while(1)
    {
        std::cout << "Choose between the 4 levels to display the msg\n";
        std::cin >> input;
        if (input == "exit")
            break ;
        harl.complain(input); 
    }
    return (0);
}