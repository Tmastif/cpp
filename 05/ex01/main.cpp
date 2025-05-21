/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:51:30 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/21 16:35:03 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Form.h"
#include <ostream>

int     main(void)
{
    Form b("form", 20, 100);
    

    /* {
        std::cout << "instantiating a bureaucrat:\n";
        Bureaucrat one("Ted", 2);
        std::cout << "using copy cntr:\n";
        Bureaucrat two(one);
        std::cout << two;
        std::cout << "incrementing to a valid grade:\n";
        one.incGrade();
        std::cout << one;
        std::cout << "incrementing to a invalid grade:\n";
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
        Bureaucrat three("bill", 154);
        std::cout << three;
        std::cout << "decrementing a grade:\n";
        three.decGrade();
        std::cout << three;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }*/

    
    return (0);
}