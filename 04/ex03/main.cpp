/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:42:58 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/07 13:11:47 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

int main(void)
{
    
    //cloning / copy cntr / assigment cntr
    Ice one;
    AMateria *two = one.clone();
    std::cout << "type after cloning ice: " << two->getType() << std::endl;
    
    Ice three; 
    three = one;
    std::cout << "materia type after assiging from ice: " << three.getType() << std::endl;
    
    
    
    return (0);
}