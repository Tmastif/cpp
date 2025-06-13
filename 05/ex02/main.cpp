/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:51:30 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/13 13:39:10 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <ostream>

void    testShrubbery(Bureaucrat &a);
void    testRobotomy(Bureaucrat &a);
void    testPardon(Bureaucrat &a);

int     main(void)
{
    
    Bureaucrat alfred("Alfred", 1);
    // testShrubbery(alfred); //145 137
    // testRobotomy(alfred); //72 45
    testPardon(alfred); //25 5

    

    
    return (0);
}

void    testShrubbery(Bureaucrat &a)
{
    ShrubberyCreationForm one("targetOne");
    
    std::cout << "\n##Trying to execute unsigen form:\n";
    a.executeForm(one);
    std::cout << "\n##Signing the form and trying again:\n";
    try
    {
        a.signForm(one);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << '\n';
    }   
    a.executeForm(one);
}

void    testRobotomy(Bureaucrat &a)
{
    RobotomyRequestForm one("targetOne");
    
    std::cout << "\n##Trying to execute unsigen form:\n";
    a.executeForm(one);
    std::cout << "\n##Signing the form and trying again:\n";
    try
    {
        a.signForm(one);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << '\n';
    }   
    a.executeForm(one);
}

void    testPardon(Bureaucrat &a)
{
    PresidentialPardonForm one("targetOne");
    
    std::cout << "\n##Trying to execute unsigen form:\n";
    a.executeForm(one);
    std::cout << "\n##Signing the form and trying again:\n";
    try
    {
        a.signForm(one);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << '\n';
    }   
    a.executeForm(one);
}