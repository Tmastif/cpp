/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:42:12 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/17 15:33:04 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"
#include <iostream>


int     main(void)
{
    Data data;
    data.value = 66;
    data.str = "yellow bricks";
    
    std::cout << "Pointer as integer:\n";
    uintptr_t nbr = Serializer::serialize(&data);
    std::cout << nbr << std::endl;
    std::cout << "Integer back to pointer:\n";
    std::cout << Serializer::deserialize(nbr) << std::endl;
    std::cout << "Data's pointer to compare:\n";
    std::cout << &data << std::endl;
    
    std::cout << "\nUsing the returned pointer of struct:\n";
    
    Data* ptr = Serializer::deserialize(nbr);
    
    std::cout << "ptr->value: " << ptr->value << std::endl;
    std::cout << "ptr->str: " << ptr->str << std::endl;
    
    ptr->value = 99;
    ptr->str = "green grass";

    std::cout << "After modification:" << std::endl;
    std::cout << "data.value: " << data.value << std::endl;
    std::cout << "data.str: " << data.str << std::endl;
    
    return (0);
}