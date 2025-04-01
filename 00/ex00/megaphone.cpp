/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:14:31 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/21 12:04:15 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

std::string toUpperCase(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
    return (str);
}

int main(int ac, char *av[])
{
    if (ac > 1)
    {
        for (int i = 1; i < ac; i++)
            std::cout<< toUpperCase(av[i]);   
         std::cout<< "\n";
    }
    else if (ac == 1)
    {
        std::string default_str = " * loud and unbearable speakers noise * ";
        std::cout<< toUpperCase(default_str) <<std::endl;
    }
    return 0;
}
