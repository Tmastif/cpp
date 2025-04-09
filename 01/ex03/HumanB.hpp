/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:19:46 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/09 13:54:47 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

// HumanB use a pointer to Weapon.
// He may not always have a weapon.
// A pointer can be null, representing the absence of a weapon.
// therefore he could be unarmed and change weapons later.
class HumanB
{
  private:
	std::string name;
	Weapon *weapon;

  public:
	HumanB(std::string name);
	void setWeapon(Weapon &weapon);
	void attack(void);
};

#endif