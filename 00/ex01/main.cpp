/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:13:31 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/01 18:23:13 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main(void)
{
    PhoneBook   book;
    std::string start_msg = "Choose between ADD SEARCH or EXIT";
    std::string input;
    
    while (1)
    {
        std::cout << start_msg << std::endl;
        std::cin >> input;
        
        if (input == "ADD")
        {
            Contact newContact = add();
            book.addcontact(newContact);
        }
        else if (input == "SEARCH")
        {
            book.displayContacts();
            book.displayFullContact();
        }
        else if (input == "EXIT")
            break ;
    }
    return (0);
}

