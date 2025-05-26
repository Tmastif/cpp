/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:26:04 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/26 23:26:51 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.h"
#include "Bureaucrat.h"
#include <iostream>
#include <ctime>
#include <cstdlib> //for rand()

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "Robotomy has been constructed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm has been destroyed\n";
}
 
void        RobotomyRequestForm::exeAction(void) const
{
    std::string msg;
    std::srand(std::time(0));
    
    msg = " has been robotomized SUCCSSESFULLY !\n";
    if (std::rand() % 2 == 0)
        msg = " has FAILED to robotomize !\n";
    
    std::cout << "* Drrrrrilling noises *\n" << _target
    << msg;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
AForm("RobotomyRequestForm", 72, 45)
{
    _target = other._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return (*this);
}