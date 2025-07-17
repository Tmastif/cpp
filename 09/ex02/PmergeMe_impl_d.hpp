/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_impl_d.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:55:43 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/17 15:19:42 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "PmergeMe.hpp"

// Ford-Johnson sort (returns a deque of sorted indices)
template <typename Container>
std::deque<int> PmergeMe::fj_sort(
    const Container &seq,
    const std::deque<int> &indices,
    int &comparisons)
{
    unsigned int n = indices.size();
    if (n <= 1)
        return indices;
    std::deque<Pair> pairs;
    unsigned int i = 0;
    for (; i + 1 < n; i += 2)
    {
        int idx1 = indices[i];
        int idx2 = indices[i + 1];
        if (seq[idx1] > seq[idx2])
            pairs.push_back(Pair(idx1, idx2));
        else
            pairs.push_back(Pair(idx2, idx1));
        comparisons++;
    }
    if (i < n)
        pairs.push_back(Pair(-1, indices[n - 1]));
    // Build main_indices from the larger of each pair
    std::deque<int> main_indices;
    for (unsigned int j = 0; j < pairs.size(); ++j)
    {
        if (pairs[j].main_idx != -1)
            main_indices.push_back(pairs[j].main_idx);
    }
    // Recursively sort the main indices
    std::deque<int> sorted_main_idx =
        fj_sort<Container>(seq, main_indices, comparisons);
    // Build pend_pairs in the same order of sorted main chain
    std::deque<Pair> pend_pairs;
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
}

// Insert in Jacobsthal order
template <typename Container>
void PmergeMe::insert_pend_jacobsthal_pairs(
    const Container &seq,
    std::deque<int> &main_chain,
    const std::deque<Pair> &pend_pairs,
    int &total_comparisons)
{
    std::deque<int> order = jacobsthal_insertion_order_d(pend_pairs.size());
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
}

// Binary insert index into sorted indices
template <typename Container>
void PmergeMe::binary_insert_idx(
    const Container &input,
    std::deque<int> &sorted_indices,
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
}