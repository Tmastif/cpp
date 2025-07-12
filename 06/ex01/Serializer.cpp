/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:34:49 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/17 15:23:19 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"

uintptr_t   Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}


Data*   Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}




Serializer::Serializer(const Serializer &other)
{
    (void) other;
}


Serializer& Serializer::operator=(const Serializer &other)
{
    (void) other;
    return (*this);
}