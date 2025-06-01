/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:42:12 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/01 13:58:19 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"
#include <iostream>


//problem with uinptr_t and c++98 !!! see makefile for flags

int     main(void)
{
    Data data;

    std::cout << "Pointer as integer:\n";
    uintptr_t nbr = Serializer::serialize(&data);
    std::cout << nbr << std::endl;
    std::cout << "Integer back to pointer:\n";
    std::cout << Serializer::deserialize(nbr) << std::endl;
    std::cout << "Data's pointer to compare:\n";
    std::cout << &data << std::endl;
    
    return (0);
}