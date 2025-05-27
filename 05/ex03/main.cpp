/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:51:30 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/27 12:07:12 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "Intern.h"
#include <ostream>
#include <cstdlib>
#include <cctype>

void    testForm(Bureaucrat &a, AForm *one);

int     main(void)
{
    std::string input;
    std::string target;
    std::string formName;
    AForm *form;
    
    int         callIntern = 1;
    
    while (1)
    {
        std::cout << "\nChose a form:  or [Q]uit\n";
        std::cout << "[1] Shrubbery Creation\n"
        << "[2] Robotomy Request\n"
        << "[3] Presidential Pardon\n";
        std::cin >> input;
        if (input == "q" || input == "Q")
            break ;
        switch (std::atoi(input.c_str()))
        {
            case 1:
            {
                formName = "Shrubbery Creation";
                break ;
            }
            case 2:
            {
                formName = "Robotomy Request";
                break;
            }
            case 3:
            {
                formName = "Presidential Pardon";
                break ;
            }
            default:
                formName = input;
                // callIntern = 0;
                // std::cout << "Invalid key\n";
            };
            
            if (callIntern)
            {
                std::cout << "Type target name:\n";
                std::cin >> target;
                Intern Jimmy;
                std::cout << "\n##Form type: " << formName << " Target: " << target << "\n";
                form = Jimmy.makeForm(formName, target);
                if (form)
                {
                    Bureaucrat alfred("Alfred", 1);
                    testForm(alfred, form);
                }
            }
    }   
    return (0);
}

void    testForm(Bureaucrat &a, AForm *one)
{   
    std::cout << "\n##Trying to execute unsigen form:\n";
    a.executeForm(*one);
    std::cout << "\n##Signing the form and trying again:\n";
    try
    {
        (*one).beSigned(a); 
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << '\n';
    }   
    a.executeForm(*one);
}

void    testRobotomy(Bureaucrat &a, AForm *one)
{   
    std::cout << "\n##Trying to execute unsigen form:\n";
    a.executeForm(*one);
    std::cout << "\n##Signing the form and trying again:\n";
    try
    {
        (*one).beSigned(a); 
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << '\n';
    }   
    a.executeForm(*one);
}

void    testPardon(Bureaucrat &a, AForm *one)
{   
    std::cout << "\n##Trying to execute unsigen form:\n";
    a.executeForm(*one);
    std::cout << "\n##Signing the form and trying again:\n";
    try
    {
        (*one).beSigned(a); 
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << '\n';
    }   
    a.executeForm(*one);
}