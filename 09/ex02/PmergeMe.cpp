/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:43:35 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/08 13:16:26 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <sstream>
#include <iostream>

bool    PmergeMe::parse_input(int ac, char **av)
{
    if (!av)
        return false;
    
    std::string str;
    int         value;

    for (int i = 1; i < ac; i++)
    {
        str = (av[i]); 
        if (str.empty())
                return false;
        std::istringstream iss(str);
        iss >> value;
        if (iss.fail() || !iss.eof())
            return false;
        if (value < 0)
            return false;
        v.push_back(value);
        d.push_back(value);
    }
    return true;
};


void    PmergeMe::print_v(void)
{
    for (unsigned long i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    };
    std::cout << std::endl;
};

void    PmergeMe::print_d(void)
{
    for (unsigned long i = 0; i < d.size(); i++)
    {
        std::cout << d[i] << " ";
    };
    std::cout << std::endl;
};