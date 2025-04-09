/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:19:46 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/09 13:54:31 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

// HumanA use a reference to Weapon.
// he is always armed, meaning he will always have a Weapon.
// A reference cannot be null and must be initialized at construction.
class HumanA
{
  private:
	std::string name;
	Weapon &weapon;

  public:
	HumanA(std::string name, Weapon &weapon);
	void attack(void);
};

#endif