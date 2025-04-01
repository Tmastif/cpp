/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:36:09 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/24 10:40:51 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static std::string     add_var(std::string var_name)
{
    std::string input;
    
    while (1)
    {
        std::cout << "Enter contact's " + var_name + ":" << std::endl;
        std::cin >> input;
        if (input == "")
        {
            std::cout << "String can not be empty" << std::endl;
            continue ;
        }
        break ;
    }
    return (input);
}

Contact   add(void)
{
    std::string input;
    Contact     newContact;
    
    input = add_var("first name");
    newContact.first_name = input;
    input = add_var("last name");
    newContact.last_name = input;
    input = add_var("nickname");
    newContact.nickname = input;
    input = add_var("darkest's secret");
    newContact.darkest_secret = input;
    input = add_var("phone number");
    newContact.phone_nbr = input;
    return (newContact);
}
