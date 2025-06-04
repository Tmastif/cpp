/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:42:12 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/04 14:24:59 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"
#include <ctime>
#include <cstdlib>
#include <iostream>


int     main(void)
{
    Base base;
    srand(time(NULL));
    //pointer check
    {
        Base *one = base.generate();
        base.identify(one);
        delete (one);
    }
    
    //ref check
    Base *one = base.generate();
    base.identify(*one);
    delete (one);
    
    return (0);
}