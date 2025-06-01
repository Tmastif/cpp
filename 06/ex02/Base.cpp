/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:04:15 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/01 14:59:37 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Base::identify(Base &p)
{
    std::cout << "ref check\n";
    p.printId();
}

void Base::identify(Base *p)
{
    std::cout << "pointer check\n";
    p->printId();
}

Base * Base::generate(void)
{
    Base *base;
    int random;
    
    // srand(time(NULL));
    random = rand() % 3;
    switch (random)
    {
        case 0:
        {
            base = new A();
            break ;
        }
        case 1:
        {
            base = new B();
            break ;
        }
        default:
            base = new C();
    }
    return (base);
}

Base::~Base(void)
{
    std::cout << "Base destructor\n";
}