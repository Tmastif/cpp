/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:23:58 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/02 19:12:56 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

template <typename T>
void    iter(T *array, int length, void (*func)(T&))
{
    for (int i = 0; i < length; i++)
        func(array[i]);
}

template <typename T>
void    iter(T *array, int length, void (*func)(const T&))
{
    for (int i = 0; i < length; i++)
        func(array[i]);
}

//tests
template <typename T>
void printElem(const T& elem)
{
    std::cout << elem << "\n";
}

template <typename T>
void openZooGate(T& elem)
{
    elem += " has escaped";
}

template <typename T>
void minusOne(T& elem)
{
    elem -= 1;
}

#endif