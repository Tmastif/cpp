/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:52:46 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/27 11:07:17 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int     main(void)
{
    std::string str;

    str = "HI THIS IS BRAIN";
    std::stringode *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Memory adress of the string vaiable:\n";
    std::cout << &str << std::endl;
    std::cout << "Memory adress help by stringPTR:\n";
    std::cout << stringPTR << std::endl;
    std::cout << "Memory adress held by stringREF:\n";
    std::cout << &stringREF << "\n" << std::endl;
    
    std::cout << "The value of the string variable:\n";
    std::cout << str << std::endl;
    std::cout << "The value of stringPTR:\n";
    std::cout << *stringPTR << std::endl;
    std::cout << "The value of stringREF:\n";
    std::cout << stringREF << std::endl;
    return (0);
}
