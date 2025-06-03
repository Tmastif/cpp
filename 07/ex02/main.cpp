/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:42:12 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/03 16:00:27 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.h"

int     main(void)
{
    // Default constructor
    Array<int> a;
    std::cout << "Default size: " << a.size() << std::endl; // Expected: 0
    
    // Construction with size
    Array<int> b(5);
    std::cout << "Size: " << b.size() << std::endl; // Expected: 5
    for (int i = 0; i < b.size(); ++i)
        std::cout << b[i] << " "; // Expected: 0 0 0 0 0
    std::cout << std::endl;
    
    // Element Assignment and Access
    for (int i = 0; i < b.size(); ++i)
    b[i] = i * 10;
    for (int i = 0; i < b.size(); ++i)
        std::cout << b[i] << " "; // Expected: 0 10 20 30 40
    std::cout << std::endl;
    
    // Copy Construction
    Array<int> c = b;
    c[0] = 999;
    std::cout << "Original b[0]: " << b[0] << std::endl; // Expected: 0
    std::cout << "Copy c[0]: " << c[0] << std::endl;     // Expected: 999

    // Assignment Operator
    Array<int> d(3);
    d = b;
    d[1] = 888;
    std::cout << "Original b[1]: " << b[1] << std::endl; // Expected: 10
    std::cout << "Assigned d[1]: " << d[1] << std::endl; // Expected: 888
    
    // Out-of-Bounds Access
    try
    {
        std::cout << b[10] << std::endl; // Should throw
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl; // Expected: exception message
    }
    
    // Const Array Access
    const Array<int> e = b;
    std::cout << "Const e[2]: " << e[2] << std::endl; // Expected: 20
    // e[2] = 5; // Should not compile

    return (0);
}