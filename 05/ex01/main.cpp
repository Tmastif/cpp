/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:51:30 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/13 13:27:54 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Form.h"
#include <ostream>

int     main(void)
{
    std::cout << "Form can't be made with grades out of range:\n";
    try
    {
        Form c("Faily", 1, 0);    
        std::cout << c;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "########\n";
    //signing
    {
        Form b("Certifacte1", 20, 100);
        std::cout << b;
        Bureaucrat Eddi("Eddi", 1);
        std::cout << Eddi;
        Eddi.signForm(b);
        std::cout << b;
    }
    std::cout << "#########\n";
    //failing to sign
    {
        Form b("Certifacte2", 1, 100);
        std::cout << b;
        Bureaucrat Tom("Tom", 2);
        std::cout << Tom;
        Tom.signForm(b);
        std::cout << b;
    }
    return (0);
}