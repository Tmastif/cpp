/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 11:59:06 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/13 13:23:11 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

Bureaucrat::Bureaucrat (const std::string &name, int grade) : _name(name)
{
        if (grade < highestGrade)
                throw GradeTooHighException();
        if (grade > lowestGrade)
                throw GradeTooLowException();
        _grade = grade;
        std::cout << _name << " has been constructed\n";
}

Bureaucrat::Bureaucrat (const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
        std::cout << "copy cntr\n";
}

//cannot assign name since its a const member
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
        if (this != &other)
        {
                _grade = other._grade;
                std::cout << "copy assigment. excluding name\n";
        }
        return (*this);
}

Bureaucrat::~Bureaucrat (void)
{
        std::cout << _name << " has been destroyed\n";
}

//FUNCTIONS

std::string Bureaucrat::getName(void) const
{
        return (_name);
}

int     Bureaucrat::getGrade(void) const
{
        return (_grade);
}

void    Bureaucrat::incGrade(void)
{
        if (_grade == highestGrade)
                throw GradeTooHighException();
        _grade--;
}

void    Bureaucrat::decGrade(void)
{
        if (_grade == lowestGrade)
                throw GradeTooLowException();
        _grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bur)
{
        os << bur.getName() 
        << ", bureaucrat grade "
        << bur.getGrade() << std::endl;
        return (os);
}

void    Bureaucrat::signForm(Form &f)
{
        try 
        {        
                f.beSigned(*this);
                std::cout << _name << " signed " << f.getName() << "\n";
        }
        catch (std::exception &e)
        {
                std::cout << _name
                << " couldn't sign "
                << f.getName()
                << " because "
                << e.what() << std::endl;        
        }
}