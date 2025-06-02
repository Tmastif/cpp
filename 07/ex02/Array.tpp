/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:49:33 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/02 20:23:16 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    //     Array(const Array &other);
    //     Array& operator=(const Array &other);

    //     int     size(void) const;
#include "Array.h"

template <typename T>
Array<T>::Array(void) : _data(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n) {}

template <typename T>
Array<T>::~Array()
{
    delete[] (_data);
}

template <typename T>
Array<T>::Array(const Array &other)
{
    
}