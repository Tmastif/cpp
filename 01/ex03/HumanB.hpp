/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:19:46 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/27 11:56:44 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>

class HumanB
{
    private:
        std::string name;
        Weapon  weapon;

    public:
        HumanB(std::string name);
        void    setWeapon(Weapon weapon);
        void    attack(void);
};