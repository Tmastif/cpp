/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:10:03 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/27 11:52:35 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Weapon
{
    private:
        std::string type;

    public:
        Weapon(void);
        Weapon(std::string type);
        const   std::string& getType(void);
        void    setType(const std::string& type);
};