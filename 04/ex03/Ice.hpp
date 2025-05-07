/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:40:14 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/07 13:10:49 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        // Ice& operator=(const Ice &other);
        AMateria*   clone() const;
        void        use(ICharacter& target);
};