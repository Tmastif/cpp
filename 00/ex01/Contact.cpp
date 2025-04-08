/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:47:16 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/08 14:01:45 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>


std::string   Contact::getFirstname(void) const
{
    return (this->first_name);
}

std::string   Contact::getLastname(void) const
{
    return (this->last_name);
}

std::string    Contact::getNickname(void) const
{
    return (this->nickname);
}

std::string    Contact::getSecret(void) const
{
    return (this->darkest_secret);
}

std::string    Contact::getPhone(void) const
{
    return (this->phone_nbr);
}

void    Contact::setFirstname(std::string name)
{
    this->first_name = name;
}

void    Contact::setLastname(std::string name)
{
    this->last_name = name;
}

void    Contact::setNickname(std::string name)
{
    this->nickname = name;
}

void    Contact::setSecret(std::string str)
{
    this->darkest_secret = str;
}

void    Contact::setPhone(std::string str)
{
    this->phone_nbr = str;
}
