/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:42:12 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/01 15:10:37 by ilazar           ###   ########.fr       */
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