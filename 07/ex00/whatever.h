/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:44:13 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/02 18:24:22 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
#define WHATEVER_H

template <typename T>
void swap(T &a, T &b)
{
    T   temp;

    temp = a;
    a = b;
    b = temp;
}

template <typename T>
T   min(T a, T b)
{
    if (a < b)
        return (a);
    return (b);
}

template <typename T>
T   max(T a, T b)
{
    if (a > b)
        return (a);
    return (b);
}


#endif