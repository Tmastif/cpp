/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:43:35 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/17 16:11:51 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>


PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe (const PmergeMe &other) : v(other.v), d(other.d) {}
PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        v = other.v;
        d = other.d;
    }
    return *this;
}

PmergeMe::~PmergeMe(void) {}

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
}

int    PmergeMe::action(int ac, char **av)
{
    int comparisments = 0;
    if (parse_input(ac, av))
    {
        std::cout << "Before:   ";
        print(v);
        
        std::vector<int> indices_v(v.size());
        std::deque<int> indices_d(d.size());
        for (size_t i = 0; i < v.size(); i++)
            indices_v[i] = i;
        for (size_t i = 0; i < d.size(); i++)
            indices_d[i] = i;
        
        { // VECTOR
            clock_t start = clock();
            std::vector<int> sorted_idx = fj_sort(v, indices_v, comparisments);
            clock_t end = clock();
            double vec_time = double(end - start) / CLOCKS_PER_SEC * 100;
            std::cout << "After:    ";
            for (size_t i = 0; i < sorted_idx.size(); i++)
                std::cout << v[sorted_idx[i]] << " ";
            std::cout << std::endl;
            std::cout << "Comparisons: " << comparisments << std::endl;
            std::cout << "Time to process a range of " << v.size() << " elements with std::vector : "
            << vec_time << " us" <<  std::endl;
        }
        comparisments = 0;
        { // DEQUE
            clock_t start = clock();
            std::deque<int> sorted_idx = fj_sort(d, indices_d, comparisments);
            clock_t end = clock();
            double deq_time = double(end - start) / CLOCKS_PER_SEC * 100;
            std::cout << "Comparisons: " << comparisments << std::endl;
            std::cout << "Time to process a range of " << d.size() << " elements with std::deque : "
            << deq_time << " us" <<  std::endl;
        }
        return 0;
    }
    std::cerr << "Parsing failed. Please provide one or more positive integers\n";
    return 1;
}


//VECTOR
// Jacobsthal insertion order
std::vector<int> PmergeMe::jacobsthal_insertion_order_v(int m)
{
    std::vector<int> jacobs = jacobsthal_numbers_v(m);
    std::vector<int> order;
    int prev = 0;
    for (unsigned int i = 0; i < jacobs.size(); i++)
    {
        int curr = jacobs[i];
        for (int j = curr - 1; j >= prev; j--)
        {
            if (j < m)
                order.push_back(j);
            if (j == 0)
                break ;
        }
        prev = curr;
    }
    for (int j = m - 1; j >= prev; j--)
    {
        order.push_back(j);
        if (j == 0)
            break ;
    }
    return order;
}

// Jacobsthal numbers up to max_n
std::vector<int> PmergeMe::jacobsthal_numbers_v(int max_n)
{
    std::vector<int> jacobs;
    int j0 = 0;
    int j1 = 1;
    jacobs.push_back(j1);
    while (1)
    {
        int next = j1 + 2 * j0;
        if (next > max_n)
            break;
        jacobs.push_back(next);
        j0 = j1;
        j1 = next;
    }
    return jacobs;
}


//DEQUE
// Jacobsthal insertion order
std::deque<int> PmergeMe::jacobsthal_insertion_order_d(int m)
{
    std::deque<int> jacobs = jacobsthal_numbers_d(m);
    std::deque<int> order;
    int prev = 0;
    for (unsigned int i = 0; i < jacobs.size(); i++)
    {
        int curr = jacobs[i];
        for (int j = curr - 1; j >= prev; j--)
        {
            if (j < m)
                order.push_back(j);
            if (j == 0)
                break ;
        }
        prev = curr;
    }
    for (int j = m - 1; j >= prev; j--)
    {
        order.push_back(j);
        if (j == 0)
            break ;
    }
    return order;
}

// Jacobsthal numbers up to max_n
std::deque<int> PmergeMe::jacobsthal_numbers_d(int max_n)
{
    std::deque<int> jacobs;
    int j0 = 0;
    int j1 = 1;
    jacobs.push_back(j1);
    while (1)
    {
        int next = j1 + 2 * j0;
        if (next > max_n)
            break;
        jacobs.push_back(next);
        j0 = j1;
        j1 = next;
    }
    return jacobs;
}