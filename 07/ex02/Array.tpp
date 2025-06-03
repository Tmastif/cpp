/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:49:33 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/03 15:47:56 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.h"

template <typename T>
Array<T>::Array(void) : _data(new T[0]()), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::~Array()
{
    delete[] (_data);
}

template <typename T>
Array<T>::Array(const Array &other) : _data(new T[other._size]()), _size(other._size)
{
    unsigned int    i;
    
    for (i = 0; i < _size; i++)
        _data[i] = other._data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
    unsigned int    i;
    
    if (this != &other)
    {
        delete[] (_data);
        _size = other._size;
        _data = new T[_size]();
        for (i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
    return (*this);
}

template <typename T>
int     Array<T>::size(void) const
{
    return (_size);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return (_data[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return (_data[index]);
}