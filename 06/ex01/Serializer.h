/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:34:49 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/17 15:22:51 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <stdint.h>
#include <string>

struct Data
{
    int         value;
    std::string  str;
};

class Serializer
{
    private:
        Serializer() {} ;
        Serializer(const Serializer &other);
        Serializer& operator=(const Serializer &other);
    public:
        ~Serializer() {};
        
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif


/*
uintptr_t is an unsigned integer type
that is guaranteed to be large enough to hold any pointer value.
*/