/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:50:29 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/10 14:42:33 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>
#include <string>
#include <iostream>

int     main(int ac, char **av)
{
    Harl harl;
    
    if (ac != 1)
        harl.complain(av[1]);
    return (0);
}