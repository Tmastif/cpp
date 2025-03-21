/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:13:31 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/21 16:40:44 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

class Contact {

    static int contactCount;
    
    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string darkest_secret;
        std::string phone_nbr;

    
        Contact(std::string first_name, 
            std::string last_name, 
            std::string nickname, 
            std::string darkest_secret, 
            std::string phone_nbr)
        {
            this->first_name = first_name;
            this->last_name = last_name;
            this->nickname = nickname;
            this->darkest_secret = darkest_secret;
            this->phone_nbr = phone_nbr;
            contactCount++;
        }
};

int Contact::contactCount = 0;

class   PhoneBook {


};

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
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string secret;
    std::string phone_nbr;

    first_name = add_var("first name");
    last_name = add_var("last name");
    nickname = add_var("nickname");
    secret = add_var("darkest's secret");
    phone_nbr = add_var("phone number");

    Contact contact(first_name, last_name, nickname, secret, phone_nbr);
    return (contact);
}

int main(void)
{
    std::string start_msg = "Choose between ADD SEARCH or Exit";
    std::string input;
    
    //start msg
    std::cout << start_msg << std::endl;
    std::cin >> input;
    
    if (input == "ADD") add();
    
    // else if (input == "SEARCH")
    // else if (input == "EXIT")
    else std::cout << start_msg << std::endl;
    
    return (0);
}

