/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:58:58 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/09 13:37:18 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.h"

template <typename T, typename Container>
typename Container::iterator     MutantStack<T, Container>::begin()
{
    return (this->c.begin());
}

template <typename T, typename Container>
typename Container::const_iterator     MutantStack<T, Container>::begin() const
{
    return (this->c.begin());
}

template <typename T, typename Container>
typename Container::iterator     MutantStack<T, Container>::end()
{
    return (this->c.end());
}

template <typename T, typename Container>
typename Container::const_iterator     MutantStack<T, Container>::end() const
{
    return (this->c.end());
}


