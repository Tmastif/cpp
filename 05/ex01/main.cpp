/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:51:30 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/26 16:09:44 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Form.h"
#include <ostream>

int     main(void)
{

    //Form can't be made with grades out of range
    // try
    // {
    //     Form c("Faily", 1, 0);    
    //     std::cout << c;
    // }
    // catch (const std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    //signing
    {
        Form b("Certifacte1", 20, 100);
        std::cout << b;
        Bureaucrat Eddi("Eddi", 1);
        Eddi.signForm(b);
        std::cout << b;
    }
    std::cout << "#########\n";
    //failing to sign
    {
        Form b("Certifacte2", 1, 100);
        std::cout << b;
        Bureaucrat Tom("Tom", 2);
        Tom.signForm(b);
        std::cout << b;
    }    

    
    return (0);
}