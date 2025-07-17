/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:59:31 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/17 16:03:49 by ilazar           ###   ########.fr       */
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
        void    print(const Container &a) const;
        

        //VECTOR
        // Ford-Johnson sort (returns vector of sorted indices)
        template <typename Container>
        std::vector<int> fj_sort(
            const Container &seq,
            const std::vector<int> &indices,
            int &comparisons);

        // Insert in Jacobsthal order
        template <typename Container>
        void insert_pend_jacobsthal_pairs(
            const Container &seq,
            std::vector<int> &main_chain,
            const std::vector<Pair> &pend_pairs,
            int &total_comparisons);
        
        // Binary insert index into sorted indices
        template <typename Container>
        void binary_insert_idx(
            const Container &input,
            std::vector<int> &sorted_indices,
            int idx,
            int &comp,
            int right_bound);

        // Jacobsthal insertion order
        std::vector<int> jacobsthal_insertion_order_v(int m);

        // Jacobsthal numbers up to max_n
        std::vector<int> jacobsthal_numbers_v(int max_n);


        
        //DEQUE
        // Ford-Johnson sort (returns vector of sorted indices)
        template <typename Container>
        std::deque<int> fj_sort(
            const Container &seq,
            const std::deque<int> &indices,
            int &comparisons);

        // Insert in Jacobsthal order
        template <typename Container>
        void insert_pend_jacobsthal_pairs(
            const Container &seq,
            std::deque<int> &main_chain,
            const std::deque<Pair> &pend_pairs,
            int &total_comparisons);

        // Binary insert index into sorted indices
        template <typename Container>
        void binary_insert_idx(
            const Container &input,
            std::deque<int> &sorted_indices,
            int idx,
            int &comp,
            int right_bound);
        
        // Jacobsthal insertion order
        std::deque<int> jacobsthal_insertion_order_d(int m);

        // Jacobsthal numbers up to max_n
        std::deque<int> jacobsthal_numbers_d(int max_n);
        
};

#include "PmergeMe_impl_v.hpp"
#include "PmergeMe_impl_d.hpp"