/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:47:49 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/13 13:33:18 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.h"
#include "Bureaucrat.h"
#include <iostream>

AForm::AForm(const std::string &name, int signGrade, int excuteGrade) :
_name(name), _signGrade(signGrade), _executeGrade(excuteGrade)
{
    if (signGrade < highestGrade)
            throw GradeTooHighException();
    if (signGrade > lowestGrade)
            throw GradeTooLowException();
    if (excuteGrade < highestGrade)
            throw GradeTooHighException();
    if (excuteGrade > lowestGrade)
            throw GradeTooLowException();
    _isSigned = false;
    std::cout << _name << " Aform has constructed\n";
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned),
_signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
    std::cout << _name << " copy cntr\n";   
}

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    std::cout << _name << " copy assigment. only isSigned is copied\n"; 
    return (*this);
}

AForm::~AForm()
{
    std::cout << _name << " AForm has been destructed\n"; 
}

//FUNCTIONS

std::string AForm::getName(void) const
{
    return (_name);
}

bool    AForm::getIsSigned(void) const
{
    return(_isSigned);
}

int     AForm::getSignGrade(void) const
{
    return(_signGrade);
}

int     AForm::getExecuteGrade(void) const
{
    return(_executeGrade);
}


void    AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= _signGrade)
    {
        _isSigned = true;
    }
    else
        throw (GradeTooLowException());
}


std::ostream& operator<<(std::ostream &os, const AForm &form)
{
    os << form.getName()
    << " Required sign grade: "
    <<  form.getSignGrade()
    << ". Required execute grade: "
    <<  form.getExecuteGrade()
    << ". Form signed: ";
    if (form.getIsSigned())
        os << "Yes\n";
    else
        os << "No\n";
    return(os);
}

void    AForm::execute(Bureaucrat const &executor) const
{
    if (_isSigned != true)
        throw (FormNotSignedException());
    if (executor.getGrade() > _executeGrade)
        throw (GradeTooHighException());
    exeAction();
}