/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:19:06 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/01 12:33:26 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include <iostream>


int     main(int ac, char **av)
{
    
    if (ac == 2)
        ScalarConverter::convert(av[1]);
    else
        std::cout << "Please enter a vaild input\n";
    
    // Tests
/*  (void) ac;
    (void) av;
    std::string test_cases[] =
    {
        "'a'",           // char
        "55",            // int
        "-55",           // negative int
        "2147483647",    // max int
        "-2147483648",   // min int
        "2147483648",    // overflow (invalid)
        "3.14f",         // float
        "3.14",          // double
        "-inf",          // double pseudo-literal
        "+inff",         // float pseudo-literal
        "nan",           // double pseudo-literal
        "abc",           // invalid
        "123abc",        // invalid
        "123.456abc",    // invalid
        ".",             // invalid
        "-",             // invalid
        "+"              // invalid
    };

    for (size_t i = 0; i < sizeof(test_cases)/sizeof(test_cases[0]); i++)
    {
        std::cout << "\n##Testing: " << test_cases[i] << " ##\n";
        ScalarConverter::convert(test_cases[i]);
    } */
    return 0;
}