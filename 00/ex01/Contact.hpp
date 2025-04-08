/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:53:43 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/08 14:11:50 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string darkest_secret;
        std::string phone_nbr;
        
public:
        std::string    getFirstname(void) const;
        std::string    getLastname(void) const;
        std::string    getNickname(void) const;
        std::string    getSecret(void) const;
        std::string    getPhone(void) const;
        
        void    setFirstname(std::string name);
        void    setLastname(std::string name);
        void    setNickname(std::string name);
        void    setSecret(std::string str);
        void    setPhone(std::string str);
};

#endif