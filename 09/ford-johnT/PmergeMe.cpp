/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:43:35 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/12 09:33:30 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>


bool    PmergeMe::parse_input(int ac, char **av)
{
    if (!av || ac == 1)
        return false;
    
    std::string str;
    int         value;

    for (int i = 1; i < ac; i++)
    {
        str = (av[i]); 
        if (str.empty())
                return false;
        std::istringstream iss(str);
        iss >> value;
        if (iss.fail() || !iss.eof())
            return false;
        if (value < 0)
            return false;
        v.push_back(value);
        d.push_back(value);
    }
    return true;
};

int    PmergeMe::action(int ac, char **av)
{
    int comparisments = 0;
    if (parse_input(ac, av))
    {
        std::cout << "Before:   ";
        print(v);
        
        std::vector<int> indices(v.size());
        for (size_t i = 0; i < v.size(); i++)
        indices[i] = i;
        
        { // VECTOR
            clock_t start = clock();
            std::vector<int> sorted_idx = fj_sort(v, indices, comparisments);
            clock_t end = clock();
            double vec_time = double(end - start) / CLOCKS_PER_SEC * 100;
            std::cout << "After:    ";
            for (size_t i = 0; i < sorted_idx.size(); i++)
                std::cout << v[sorted_idx[i]] << " ";
            std::cout << std::endl;
            std::cout << "Comparisments: " << comparisments << std::endl;
            std::cout << "Time to process a range of " << v.size() << " elements with std::vector : "
            << vec_time << " us" <<  std::endl;
        }
        comparisments = 0;
        { // DEQUE
            clock_t start = clock();
            std::vector<int> sorted_idx = fj_sort(d, indices, comparisments);
            clock_t end = clock();
            double deq_time = double(end - start) / CLOCKS_PER_SEC * 100;
            std::cout << "Comparisments: " << comparisments << std::endl;
            std::cout << "Time to process a range of " << d.size() << " elements with std::deque : "
            << deq_time << " us" <<  std::endl;
        }
        return 0;
    }
    std::cerr << "Parsing failed. Please provide one or more positive integers\n";
    return 1;
};