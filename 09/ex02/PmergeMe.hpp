/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:59:31 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/16 16:11:43 by ilazar           ###   ########.fr       */
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

    template <typename IndexType>
    struct Pair {
        IndexType main_idx;
        IndexType pend_idx;
        Pair(IndexType m, IndexType p) : main_idx(m), pend_idx(p) {}
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
        template <typename Container, typename IndexType>
        std::vector<IndexType> fj_sort(
            const Container &seq,
            const std::vector<IndexType> &indices,
            int &comparisons)
        {
            unsigned int n = indices.size();
            if (n <= 1)
                return indices;
            std::vector< Pair<IndexType> > pairs;
            unsigned int i = 0;
            for (; i + 1 < n; i += 2)
            {
                IndexType idx1 = indices[i];
                IndexType idx2 = indices[i + 1];
                if (seq[idx1] > seq[idx2])
                    pairs.push_back(Pair<IndexType>(idx1, idx2));
                else
                    pairs.push_back(Pair<IndexType>(idx2, idx1));
                ++comparisons;
            }
            if (i < n)
                pairs.push_back(Pair<IndexType>(-1, indices[n - 1]));
            // Build main_indices from the larger of each pair
            std::vector<IndexType> main_indices;
            for (unsigned int j = 0; j < pairs.size(); ++j)
            {
                if (pairs[j].main_idx != (IndexType)-1)
                    main_indices.push_back(pairs[j].main_idx);
            }
            // Recursively sort the main indices
            std::vector<IndexType> sorted_main_idx =
                fj_sort<Container, IndexType>(seq, main_indices, comparisons);
            // Build pend_pairs in the same order of sorted main chain
            std::vector< Pair<IndexType> > pend_pairs;
            for (unsigned int k = 0; k < sorted_main_idx.size(); ++k)
            {
                IndexType sorted_main = sorted_main_idx[k];
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
                if (pairs[j].main_idx == (IndexType)-1)
                    pend_pairs.push_back(pairs[j]);
            }
            // Insert the pend in Jacobsthal order
            insert_pend_jacobsthal_pairs<Container, IndexType>(seq, sorted_main_idx, pend_pairs, comparisons);
            return sorted_main_idx;
        };
        
        
        // Insert in Jacobsthal order
        template <typename Container, typename IndexType>
        void insert_pend_jacobsthal_pairs(
            const Container &seq,
            std::vector<IndexType> &main_chain,
            const std::vector<Pair<IndexType> > &pend_pairs,
            int &total_comparisons)
        {
            std::vector<IndexType> order = jacobsthal_insertion_order<IndexType>((IndexType)pend_pairs.size());
            for (unsigned int k = 0; k < order.size(); k++)
            {
                IndexType idx = order[k];
                IndexType pend_idx = pend_pairs[idx].pend_idx;
                int comparisons = 0;
                binary_insert_idx<Container, IndexType>(seq, main_chain, pend_idx, comparisons);
                total_comparisons += comparisons;
            }
        };
        
        // Binary insert index into sorted indices
        template <typename Container, typename IndexType>
        void binary_insert_idx(
            const Container &input,
            std::vector<IndexType> &sorted_indices,
            IndexType idx,
            int &comp)
        {
            int left = 0;
            int right = (int)sorted_indices.size();
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
        template <typename IndexType>
        std::vector<IndexType> jacobsthal_insertion_order(IndexType m)
        {
            std::vector<IndexType> jacobs = jacobsthal_numbers<IndexType>(m);
            std::vector<IndexType> order;
            IndexType prev = 0;
            for (unsigned int i = 0; i < jacobs.size(); i++)
            {
                IndexType curr = jacobs[i];
                for (IndexType j = curr - 1; j >= prev; j--)
                {
                    if (j < m)
                        order.push_back(j);
                    if (j == 0)
                        break ;
                }
                prev = curr;
            }
            for (IndexType j = m - 1; j >= prev; j--)
            {
                order.push_back(j);
                if (j == 0)
                    break ;
            }
            return order;
        };

        // Jacobsthal numbers up to max_n
        template <typename IndexType>
        std::vector<IndexType> jacobsthal_numbers(IndexType max_n)
        {
            std::vector<IndexType> jacobs;
            IndexType j0 = 0;
            IndexType j1 = 1;
            jacobs.push_back(j1);
            while (1)
            {
                IndexType next = j1 + 2 * j0;
                if (next > max_n)
                    break;
                jacobs.push_back(next);
                j0 = j1;
                j1 = next;
            }
            return jacobs;
        };
};