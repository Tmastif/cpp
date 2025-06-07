/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:21:43 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/07 14:18:35 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Parser.h"



int     main(int ac, char **av)
{
    if (ac == 2)
    {
        Parser parse("data.csv", av[1]);
        parse.ParseData();
        parse.printMap();
        return (0);
    }
    std::cout << "Please enter one input file\n";
    return (1);
}