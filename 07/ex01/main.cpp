/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:42:12 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/19 13:50:38 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.h"

int     main(void)
{
    std::string strArr[]  = {"The Pigeon", "The Bear", "The Bird", "The Iguana"};
    int len = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "## Printing: (const)\n";
    iter(strArr, len, printElem<std::string>);
    std::cout << "##Modifying (non-const) and printing again:\n";
    iter(strArr, len, openZooGate<std::string>);
    iter(strArr, len, minusOne<int>);
    iter(strArr, len, printElem<std::string>);

    int intArr[] = {1, 2, 3, 777};
    len = sizeof(intArr) / sizeof(intArr[0]);
    
    std::cout << "\n## Printing:\n";
    iter(intArr, len, printElem<int>);
    std::cout << "##Modifying and printing again:\n";
    iter(intArr, len, minusOne<int>);
    iter(intArr, len, printElem<int>);
    
    return (0);
}