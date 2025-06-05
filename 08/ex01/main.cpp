/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:45:23 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/05 18:54:05 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"
#include <vector>
#include <iostream>


int main(void)
{

    try
    {
        Span sp(5);

        // Prepare a vector of numbers to insert
        std::vector<int> nums;
        nums.push_back(10);
        nums.push_back(20);
        nums.push_back(30);

        // Insert 3 numbers (should succeed)
        sp.multiNumbers(nums.begin(), nums.end());
        std::cout << "Inserted 3 numbers successfully." << std::endl;

        // Insert 2 more numbers (should succeed and fill the Span)
        int more[] = {40, 50};
        sp.multiNumbers(more, more + 2);
        std::cout << "Inserted 2 more numbers successfully." << std::endl;

        // Try to insert one more (should throw)
        int extra = 60;
        sp.multiNumbers(&extra, &extra + 1);
        std::cout << "This line should not print." << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return (0);
};
