/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:51:09 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/23 13:07:47 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie 
{
    private:
        std::string name;

    public:
        Zombie(std::string zombieName);
        ~Zombie();
        void    announce(void);
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

#endif