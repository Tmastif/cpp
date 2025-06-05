/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:14:12 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/05 14:15:42 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &con, int nbr)
{
    typename T::iterator it;
    
    it = std::find(con.begin(), con.end(), nbr);
    if (it == con.end())
        throw std::runtime_error("Value not found");
    return (it);
}