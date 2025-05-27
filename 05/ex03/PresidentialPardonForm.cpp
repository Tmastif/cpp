/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:26:04 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/26 23:26:51 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.h"
#include "Bureaucrat.h"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "Presidential has been constructed" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential has been destroyed\n";
}
 
void        PresidentialPardonForm::exeAction(void) const
{
    std::cout << _target  << " has been pardoned by Zaphod Beeblebrox.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
AForm("PresidentialPardonForm", 25, 5)
{
    _target = other._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return (*this);
}