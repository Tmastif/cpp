/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:13:10 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/27 11:52:28 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <Weapon.hpp>

Weapon::Weapon(void) {}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

const std::string& Weapon::getType(void)
{
    return (this->type);
}

void    Weapon::setType(const std::string& type)
{
    this->type = type;
}