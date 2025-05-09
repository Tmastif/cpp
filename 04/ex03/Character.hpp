/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:54:39 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/09 13:59:59 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        static const int    _slots = 4;
        std::string         _name;
        AMateria *          _inventory[_slots];
        
    public:
        Character();
        Character(std::string name);
        Character(const Character &other);
        Character& operator=(const Character &other);
        ~Character();
        
        std::string const & getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        void deleteInventory(void);
        
};

#endif