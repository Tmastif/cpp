/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:40:14 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/06 15:51:19 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        AMateria*   clone() const;
        void        use(ICharacter& target);
};