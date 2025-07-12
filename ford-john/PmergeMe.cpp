/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:43:35 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/11 22:05:20 by ilazar           ###   ########.fr       */
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
        // clock_t start = clock();

        std::vector<int> indices(v.size());
        for (size_t i = 0; i < v.size(); i++)
            indices[i] = i;
        
        std::vector<int> sorted_idx = fj_sort(v, indices, comparisments);


        std::cout << "Sorted: ";
         for (size_t i = 0; i < sorted_idx.size(); i++)
            std::cout << v[sorted_idx[i]] << " ";
        std::cout << "\nComparisons: " << comparisments << std::endl;
        
        // std::vector<int> sorted_v = fj_sort(v, comparisments);
        // clock_t end = clock();
        // std::cout << "comparisments: " << comparisments << std::endl;
        // double vec_time = double(end - start) / CLOCKS_PER_SEC * 100;
        // start = clock();
        // std::deque<int> sorted_d = fj_sort(d);
        // end = clock();
        // double deq_time = double(end - start) / CLOCKS_PER_SEC * 100;
        // std::cout << "After:    ";
        // print(sorted_v);
        // std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " \
        //  << vec_time << " us" <<  std::endl;
        //  std::cout << "Time to process a range of " << d.size() <<  " elements with std::deque : " \
        //  << deq_time << " us" << std::endl;
        return 0;
    }
    std::cerr << "Parsing failed. Please provide one or more positive integers\n";
    return 1;
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


std::vector<int> PmergeMe::fj_sort(const std::vector<int> &seq,
                         const std::vector<int> &indices,
                         int &comparisments)
{
    unsigned int n = indices.size();
    if (n <= 1)
        return indices;
    
    std::vector<Pair> pairs;
    // int straggler_idx = -1;
    unsigned int i = 0;
    for (; i + 1 < n; i += 2)
    {
        int idx1 = indices[i];
        int idx2 = indices[i + 1];
        if (seq[idx1] > seq[idx2])
            pairs.push_back(Pair(idx1, idx2));
        else
            pairs.push_back(Pair(idx2, idx1));
        comparisments++;
    }
    if (i < n)
        pairs.push_back(Pair(-1, indices[n - 1]));
        // straggler_idx = indices[n - 1];

    // Build a main chain from indices of the larger of the pair
    std::vector<int> main_indices;
    for (unsigned int j = 0; j < pairs.size(); j++)
    {
        if (pairs[j].main_idx != -1)
            main_indices.push_back(pairs[j].main_idx);
    }
    
    // Recursively sort the main indices
    std::vector<int> sorted_main_idx = fj_sort(seq, main_indices, comparisments);
    
    // Build a pend vector of pairs, with the same order of the sorted main chain
    std::vector<Pair> pend_pairs;
    for(unsigned int i = 0; i < sorted_main_idx.size(); i++)
    {
        int sorted_main = sorted_main_idx[i];
        for (unsigned int j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].main_idx == sorted_main)
            {
                pend_pairs.push_back(pairs[j]);
                break ;
            }
        }
    }

    // Add any pend-only pairs (main_idx == -1)
    for (size_t j = 0; j < pairs.size(); j++) {
        if (pairs[j].main_idx == -1)
            pend_pairs.push_back(pairs[j]);
    }

    // Insert the pend after their main pair, in Jacobsthal order
    insert_pend_jacobsthal_pairs(seq, sorted_main_idx, pend_pairs, comparisments);

    return sorted_main_idx;  
};


void     PmergeMe::insert_pend_jacobsthal_pairs(const std::vector<int> &seq,
                                        std::vector<int> &main_chain,
                                        const std::vector<Pair> &pend_pairs,
                                        int &total_comparisments)
{

    std::vector<int> order = jacobsthal_insertion_order((int)pend_pairs.size());
    for (size_t k = 0; k < order.size(); ++k)
    {
        int idx = order[k];
        int pend_idx = pend_pairs[idx].pend_idx;
        int comparisons = 0;
        // Insert pend_idx into main_chain in sorted order (by value in seq), using binary search
        binary_insert_idx(seq, main_chain, pend_idx, comparisons);
        total_comparisments += comparisons;
    }
};


void PmergeMe::binary_insert_idx(const std::vector<int> &input,
                        std::vector<int> &sorted_indices,
                        int idx,
                        int &comp)
{
    int left = 0;
    int right = (int)sorted_indices.size();
    while (left < right) {
    int mid = left + (right - left) / 2;
    if (input[sorted_indices[mid]] < input[idx])
    left = mid + 1;
    else
    right = mid;
    comp++;
    }
    sorted_indices.insert(sorted_indices.begin() + left, idx);
};


std::vector<int> PmergeMe::jacobsthal_numbers(int max_n)
{
    std::vector<int> jacobs;
    int j0 = 0, j1 = 1;
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

std::vector<int> PmergeMe::jacobsthal_insertion_order(int m)
{
    std::vector<int> jacobs = jacobsthal_numbers(m);
    std::vector<int> order;
    int prev = 0;
    for (size_t i = 0; i < jacobs.size(); ++i) {
        int curr = jacobs[i];
        for (int j = curr - 1; j >= prev; --j) {
            if (j < m)
                order.push_back(j);
        }
        prev = curr;
    }
    for (int j = m - 1; j >= prev; --j)
        order.push_back(j);
    return order;
};