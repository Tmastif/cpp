/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:51:09 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/26 11:41:00 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie 
{
    std::string name;

    public:
        Zombie(std::string zombieName);
        ~Zombie();
        void    announce(void);
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

#endif