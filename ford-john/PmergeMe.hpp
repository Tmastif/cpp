/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:59:31 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/11 21:26:33 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>

class PmergeMe
{
    private:
        std::vector<int>    v;
        std::deque<int>     d;

        struct  Pair
        {
            int main_idx;
            int pend_idx;
            Pair(int m, int p) : main_idx(m), pend_idx(p) {}
        };
        
    public:
        bool    parse_input(int ac, char **av);
        
        int    action(int ac, char **av);
        
        std::vector<int> fj_sort(const std::vector<int> &seq,
                                            const std::vector<int> &indices,
                                            int &comparisments);
        void     insert_pend_jacobsthal_pairs(const std::vector<int> &seq,
                                                        std::vector<int> &main_chain,
                                                        const std::vector<Pair> &pend_pairs,
                                                        int &total_comparisments);
        void binary_insert_idx(const std::vector<int> &input,
                                        std::vector<int> &sorted_indices,
                                        int idx,
                                        int &comp);


                                            
        std::deque<int>     fj_sort(std::deque<int> seq);

        void binary_insert(std::vector<int> &vec, int val, int &comp);
        void  insert_pend_jacobsthal(std::vector<int>& main, const std::vector<int>& pend, int &total_comparisons);
        std::vector<int> jacobsthal_numbers(int max_n);
        std::vector<int> jacobsthal_insertion_order(int m);
        
        //Helpers
        void    print(const std::vector<int> &a) const;
        void    print(const std::deque<int> &a) const;
};