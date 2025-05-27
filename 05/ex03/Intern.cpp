/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:05:42 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/27 12:03:23 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"


Intern::Intern() {};

Intern::Intern(const Intern &other) { (void)other; };

Intern& Intern::operator=(const Intern &other) 
{
    (void)other;
    return (*this);
};

Intern::~Intern() {};

//FUNCTIONS

AForm* createShrubbery(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
};

AForm* createRobotomy(const std::string &target)
{
    return (new RobotomyRequestForm(target));
};

AForm* createPresidential(const std::string &target)
{
    return (new PresidentialPardonForm(target));
};


AForm*    Intern::makeForm(const std::string &name, const std::string &target)
{
    int count;
    std::string upperName = name;
    
    toUpper(upperName);
    const std::string names[] = {"SHRUBBERY CREATION",
                                "ROBOTOMY REQUEST",
                                "PRESIDENTIAL PARDON"};
    AForm* (*creators[])(const std::string&) = {createShrubbery,
                                                createRobotomy,
                                                createPresidential}; 
    
    count = sizeof(names) / sizeof(names[0]);
    for (int i = 0; i < count; i++)
    {
        if (upperName == names[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (creators[i](target));
        }
    }
    std::cout << "No such form as " << name << std::endl;
    return (NULL);
};

void     Intern::toUpper(std::string &str)
{
    for (std::string::size_type i = 0; i < str.size(); ++i)
    {
        str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }
};