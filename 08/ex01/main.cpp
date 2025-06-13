/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:45:23 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/06 22:44:37 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

int main(void)
{
    Span sp(10003);
    int    randNbr;
    
    srand(time(0));

    // Prepare a vector of numbers to insert
    std::vector<int> nums;
    for (int i = 0; i < 10000; i++)
    {
        randNbr = (rand() % 20000) + 1;
        nums.push_back(randNbr);
    }
    
    try
    {
        // Insert 10,000 numbers
        sp.multiNumbers(nums.begin(), nums.end());
        std::cout << "Inserted 10000 numbers successfully." << std::endl;

        // Insert 3 more numbers (should fill the Span)
        int more[] = {40, 50, 60};
        sp.multiNumbers(more, more + 3);
        std::cout << "Inserted 3 more numbers successfully." << std::endl;

        // Try to insert one more (should throw)
        int extra = 60;
        sp.multiNumbers(&extra, &extra + 1);
        std::cout << "This line should not print." << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    //shortest
    std::cout << "Shortest span found: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span found: " << sp.longestSpan() << std::endl;
    
    {
        Span sp1(5);

        sp1.addNumber(6);
        sp1.addNumber(3);
        sp1.addNumber(17);
        sp1.addNumber(9);
        sp1.addNumber(11);
        std::cout << "\nShortest span found: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest span found: " << sp1.longestSpan() << std::endl;
    }
    return (0);
};
