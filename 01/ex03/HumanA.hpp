/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:19:46 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/27 11:48:14 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>

class HumanA
{
    private:
        std::string name;
        Weapon  weapon;

    public:
        HumanA(std::string name, Weapon weapon);
        void    attack(void);
};