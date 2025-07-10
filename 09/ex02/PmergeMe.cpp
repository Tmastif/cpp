/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:43:35 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/10 18:27:15 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <ctime>

int    PmergeMe::action(int ac, char **av)
{
    int comparisments = 0;
    if (parse_input(ac, av))
    {
        std::cout << "Before:   ";
        print(v);
        clock_t start = clock();
        std::vector<int> sorted_v = fj_sort(v, comparisments);
        clock_t end = clock();
        std::cout << "comparisments: " << comparisments << std::endl;
        double vec_time = double(end - start) / CLOCKS_PER_SEC * 100;
        start = clock();
        std::deque<int> sorted_d = fj_sort(d);
        end = clock();
        double deq_time = double(end - start) / CLOCKS_PER_SEC * 100;
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

std::vector<int>    PmergeMe::fj_sort(std::vector<int> &seq, int &comparisments)
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
        comparisments++;
    }
    if (n % 2 == 1)
        straggler = seq[n - 1];
    else
        straggler = -1;
    
    std::vector<int> sorted_a = fj_sort(a, comparisments);
    
    std::vector<int> result = sorted_a;
    insert_pend_jacobsthal(result, b, comparisments);
    if (n % 2 == 1)
    {
        int straggler_comparisons = 0;
        binary_insert(result, straggler, straggler_comparisons);
        comparisments += straggler_comparisons;
    }
   
    return result;
};

void  PmergeMe::insert_pend_jacobsthal(std::vector<int>& main, const std::vector<int>& pend, int &total_comparisons)
{
    std::vector<int> order = jacobsthal_insertion_order(pend.size());
    for (size_t k = 0; k < order.size(); ++k)
    {
        int idx = order[k];
        int comparisons = 0;
        binary_insert(main, pend[idx], comparisons);
        total_comparisons += comparisons;
    }
};


void PmergeMe::binary_insert(std::vector<int> &vec, int val, int &comp)
{
    int left = 0;
    int right = vec.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (vec[mid] < val)
            left = mid + 1;
        else
            right = mid;
        comp++;
    }
    vec.insert(vec.begin() + left, val);
};

std::vector<int> PmergeMe::jacobsthal_insertion_order(int m)
{
    std::vector<int> jacobs = jacobsthal_numbers(m);
    std::vector<int> order;
    int prev = 0;
    for (size_t i = 0; i < jacobs.size(); ++i)
    {
        int curr = jacobs[i];
        for (int j = curr - 1; j >= prev; --j)
        {
            if (j < m)
                order.push_back(j);
        }
        prev = curr;
    }
    // If any indices remain, insert them in reverse order
    for (int j = m - 1; j >= prev; --j)
        order.push_back(j);
    return order;
};

std::vector<int> PmergeMe::jacobsthal_numbers(int max_n)
{
    std::vector<int> jacobs;
    int j0 = 0;
    int j1 = 1;
    jacobs.push_back(j1);
    while (true) {
        int next = j1 + 2 * j0;
        if (next > max_n)
            break;
        jacobs.push_back(next);
        j0 = j1;
        j1 = next;
    }
    return jacobs;
};