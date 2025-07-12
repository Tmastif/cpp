/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:04:15 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/17 15:42:29 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

//If the cast is valid, will get the reference to the derived class
//if not, it throws a std::bad_cast exception.
void Base::identify(Base &p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "I am A" << std::endl;
        return;
    } catch (...) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "I am B" << std::endl;
        return;
    } catch (...) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "I am C" << std::endl;
    } catch (...) {}
}

//If the cast is valid, will get a pointer to the derived type
//if not, will get a nullptr.
void Base::identify(Base *p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "I am A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "I am B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "I am C" << std::endl;
}

Base * Base::generate(void)
{
    Base *base;
    int random;
    
    base = NULL;
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