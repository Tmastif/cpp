/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:21:43 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/09 13:44:38 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Btc.h"



int     main(int ac, char **av)
{
    if (ac == 2)
    {
        Btc btc("data.csv", av[1]);
        btc.ParseData();
        // btc.printMap(btc.getData());
        btc.readInputFile();
        // btc.printMap(btc.getInput());
        btc.exchange();
        return (0);
    }
    std::cout << "Please enter one input file\n";
    return (1);
}