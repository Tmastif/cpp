/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:17:16 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/27 10:42:18 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int    main(void)
{
    int n;

    n = 6;
    Zombie *horde = zombieHorde(n, "Johnny");
    
    for (int i = 0; i < n; i++)
    {
        std::cout << i + 1 << ": ";
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}