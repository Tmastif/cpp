/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:59:31 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/16 17:04:46 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
#include <list>
#include <iostream>

class PmergeMe
{
    private:
        std::vector<int>    v;
        std::deque<int>     d;

    struct Pair {
        int main_idx;
        int pend_idx;
        Pair(int m, int p) : main_idx(m), pend_idx(p) {}
    };
        
    public:
        PmergeMe();
        PmergeMe (const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();
        
        bool    parse_input(int ac, char **av);
        int     action(int ac, char **av);
        
        //Print Container
        template <typename Container>
        void    print(const Container &a) const
        {
            for (unsigned long i = 0; i < a.size(); i++)
            {
                std::cout << a[i] << " ";
            };
            std::cout << std::endl;
        };
        
        // Ford-Johnson sort (returns vector of sorted indices)
        template <typename Container>
        std::vector<int> fj_sort(
            const Container &seq,
            const std::vector<int> &indices,
            int &comparisons)
        {
            unsigned int n = indices.size();
            if (n <= 1)
                return indices;
            std::vector<Pair> pairs;
            unsigned int i = 0;
            for (; i + 1 < n; i += 2)
            {
                int idx1 = indices[i];
                int idx2 = indices[i + 1];
                if (seq[idx1] > seq[idx2])
                    pairs.push_back(Pair(idx1, idx2));
                else
                    pairs.push_back(Pair(idx2, idx1));
                ++comparisons;
            }
            if (i < n)
                pairs.push_back(Pair(-1, indices[n - 1]));
            // Build main_indices from the larger of each pair
            std::vector<int> main_indices;
            for (unsigned int j = 0; j < pairs.size(); ++j)
            {
                if (pairs[j].main_idx != -1)
                    main_indices.push_back(pairs[j].main_idx);
            }
            // Recursively sort the main indices
            std::vector<int> sorted_main_idx =
                fj_sort<Container>(seq, main_indices, comparisons);
            // Build pend_pairs in the same order of sorted main chain
            std::vector<Pair> pend_pairs;
            for (unsigned int k = 0; k < sorted_main_idx.size(); ++k)
            {
                int sorted_main = sorted_main_idx[k];
                for (unsigned int j = 0; j < pairs.size(); ++j)
                {
                    if (pairs[j].main_idx == sorted_main)
                    {
                        pend_pairs.push_back(pairs[j]);
                        break ;
                    }
                }
            }
            // Add stragglers (main_idx == -1)
            for (unsigned int j = 0; j < pairs.size(); ++j)
            {
                if (pairs[j].main_idx == -1)
                    pend_pairs.push_back(pairs[j]);
            }
            // Insert the pend in Jacobsthal order
            insert_pend_jacobsthal_pairs<Container>(seq, sorted_main_idx, pend_pairs, comparisons);
            return sorted_main_idx;
        };
        
        // Insert in Jacobsthal order
        template <typename Container>
        void insert_pend_jacobsthal_pairs(
            const Container &seq,
            std::vector<int> &main_chain,
            const std::vector<Pair> &pend_pairs,
            int &total_comparisons)
        {
            std::vector<int> order = jacobsthal_insertion_order(pend_pairs.size());
            for (unsigned int k = 0; k < order.size(); k++)
            {
                int idx = order[k];
                int pend_idx = pend_pairs[idx].pend_idx;
                int main_idx = pend_pairs[idx].main_idx;
                int right_bound = 0;
                while (right_bound < (int)main_chain.size() && main_chain[right_bound] != main_idx)
                    right_bound++;
                int comparisons = 0;
                binary_insert_idx<Container>(seq, main_chain, pend_idx, comparisons, right_bound);
                total_comparisons += comparisons;
            }
        };
        
        // Binary insert index into sorted indices
        template <typename Container>
        void binary_insert_idx(
            const Container &input,
            std::vector<int> &sorted_indices,
            int idx,
            int &comp,
            int right_bound)
        {
            int left = 0;
            int right = right_bound;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (input[sorted_indices[mid]] < input[idx])
                    left = mid + 1;
                else
                    right = mid;
                comp++;
            }
            sorted_indices.insert(sorted_indices.begin() + left, idx);
        };

        // Jacobsthal insertion order
        std::vector<int> jacobsthal_insertion_order(int m)
        {
            std::vector<int> jacobs = jacobsthal_numbers(m);
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
        };

        // Jacobsthal numbers up to max_n
        std::vector<int> jacobsthal_numbers(int max_n)
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
        };
};