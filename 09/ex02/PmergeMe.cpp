/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:43:35 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/08 15:49:34 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <ctime>

int    PmergeMe::action(int ac, char **av)
{
    if (parse_input(ac, av))
    {
        std::cout << "Before:   ";
        print(v);
        clock_t start = clock();
        std::vector<int> sorted_v = fj_sort(v);
        clock_t end = clock();
        double vec_time = double(end - start) / CLOCKS_PER_SEC * 1000000;
        start = clock();
        std::deque<int> sorted_d = fj_sort(d);
        end = clock();
        double deq_time = double(end - start) / CLOCKS_PER_SEC * 1000000;
        std::cout << "After:    ";
        print(sorted_v);
        std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " \
         << vec_time << " us" <<  std::endl;
         std::cout << "Time to process a range of " << d.size() <<  " elements with std::deque : " \
         << deq_time << " us" << std::endl;
        return 0;
    }
    std::cerr << "Parsing failed. Please provide one or more positive integers\n";
    return 1;
};

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


void    PmergeMe::print(const std::vector<int> &a) const
{
    for (unsigned long i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " ";
    };
    std::cout << std::endl;
};

void    PmergeMe::print(const std::deque<int> &a) const
{
    for (unsigned long i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " ";
    };
    std::cout << std::endl;
};

std::vector<int>    PmergeMe::fj_sort(std::vector<int> seq)
{
    unsigned int n = seq.size();
    if (n <= 1)
        return seq;

    std::vector<int> a;
    std::vector<int> b;
    int              straggler;
    for (unsigned int i = 0; i + 1 < n; i += 2)
    {
        if (seq[i] > seq[i + 1])
        {
            a.push_back(seq[i]);
            b.push_back(seq[i + 1]);
        }
        else
        {
            a.push_back(seq[i + 1]);
            b.push_back(seq[i]);
        }
    }
    if (n % 2 == 1)
        straggler = seq[n - 1];
    else
        straggler = -1;
    
    std::vector<int> sorted_a = fj_sort(a);
    
    std::vector<int> result = sorted_a;
    for (unsigned int i = 0; i < b.size(); i++)
    {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), b[i]);
        result.insert(pos, b[i]);
    }
    if (n % 2 == 1)
    {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }
    return result;
};

std::deque<int>    PmergeMe::fj_sort(std::deque<int> seq)
{
    unsigned int n = seq.size();
    if (n <= 1)
        return seq;

    std::deque<int> a;
    std::deque<int> b;
    int             straggler;
    for (unsigned int i = 0; i + 1 < n; i += 2)
    {
        if (seq[i] > seq[i + 1])
        {
            a.push_back(seq[i]);
            b.push_back(seq[i + 1]);
        }
        else
        {
            a.push_back(seq[i + 1]);
            b.push_back(seq[i]);
        }
    }
    if (n % 2 == 1)
        straggler = seq[n - 1];
    else
        straggler = -1;
    
    std::deque<int> sorted_a = fj_sort(a);
    
    std::deque<int> result = sorted_a;
    for (unsigned int i = 0; i < b.size(); i++)
    {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), b[i]);
        result.insert(pos, b[i]);
    }
    if (n % 2 == 1)
    {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }
    return result;
};