/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:23:58 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/03 15:35:12 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array
{
    private:
        T               *_data;
        unsigned int    _size;
    public:
        Array(void);
        Array(unsigned int n);
        ~Array();
        Array(const Array &other);
        Array& operator=(const Array &other);
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        

        int     size(void) const;
};

#include "Array.tpp"

#endif