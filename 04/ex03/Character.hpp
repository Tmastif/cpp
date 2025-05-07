/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:54:39 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/07 13:01:19 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

class Character
{
    private:
        AMateria *inventory[4];
    public:
        Character();
        Character(const Character &other);
        Character& operator=(const Character &other);
        ~Character();
        
        
}
