/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:47:49 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/21 16:33:55 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.h"
#include <iostream>

Form::Form(const std::string &name, int signGrade, int excuteGrade) :
_name(name), _signGrade(signGrade), _executeGrade(excuteGrade)
{
    std::cout << _name << " form has constructed\n";
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned),
_signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
    std::cout << _name << " copy cntr\n";   
}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    std::cout << _name << " copy assigment. only isSigned is copied\n"; 
    return (*this);
}

Form::~Form()
{
    std::cout << _name << " has been destructed\n"; 
}

//FUNCTIONS

std::string Form::getName(void) const
{
    return (_name);
}

bool    Form::getIsSigned(void) const
{
    return(_isSigned);
}

int     Form::getSignGrade(void) const
{
    return(_signGrade);
}

int     Form::getExecuteGrade(void) const
{
    return(_executeGrade);
}


std::ostream& operator<<(std::ostream &os, const Form &form)
{
    os << form.getName()
    << " required sign grade: "
    <<  form.getSignGrade()
    << " required execute grade: "
    <<  form.getExecuteGrade()
    << " is signed: " << form.getIsSigned()
    << std::endl;
    return(os);
}
