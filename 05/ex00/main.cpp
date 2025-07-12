/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:51:30 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/13 13:15:37 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include <ostream>

int     main(void)
{
    {
        std::cout << "instantiating a bureaucrat:\n";
        Bureaucrat one("Ted", 2);
        std::cout << "using copy cntr:\n";
        Bureaucrat two(one);
        std::cout << two;
        std::cout << "incrementing to a valid grade:\n";
        one.incGrade();
        std::cout << one;
        std::cout << "incrementing to an invalid grade:\n";
        try
        {
            one.incGrade();
        }
        catch(const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    
    std::cout << "instantiating a bureaucrat with an out of range grade:\n";
    try
    {
        Bureaucrat three("bill", 151);
        std::cout << three;
        std::cout << "decrementing a grade:\n";
        three.decGrade();
        std::cout << three;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    
    return (0);
}