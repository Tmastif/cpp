/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:17:16 by ilazar            #+#    #+#             */
/*   Updated: 2025/03/26 11:46:28 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int    main(void)
{
    //allocating memory
    Zombie *heap = newZombie("heap");
    heap->announce();
    delete heap;

    //on stack
    randomChump("stack1");
    randomChump("stack2");
    randomChump("stack3");
    
    return (0);
}