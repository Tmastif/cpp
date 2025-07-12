/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:45:23 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/20 12:28:18 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <vector>
#include <iostream>


int main(void)
{
    std::vector<int> v;
    v.push_back(22);
    v.push_back(26);
    v.push_back(34);
    v.push_back(26);
    v.push_back(34);

    std::cout << "The 3rd element: " << v[2] << std::endl;
    std::cout << "Adress of the 3rd element:       " << &v[2] << std::endl;
    
    std::cout << "\nSearching a number that doesn't exist:" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(v, 4);
        std::cout << "Found: " << *it << "\n";
    }   
    catch (std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nSearching 34:" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(v, 34);
        std::cout << "Found: " << *it << "\n";
        std::cout << "\nThe adress of the found element: " << &(*it) << "\n";
    }   
    catch (std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
};

/*
- 'it' is the iterator (returned by easyfind).
- '*it' dereferences the iterator to access the element it points to.
- '&(*it)' takes the address of that element.
*/