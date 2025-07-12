/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:59:31 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/10 18:09:50 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>

class PmergeMe
{
    private:
        std::vector<int>    v;
        std::deque<int>     d;
        
    public:
        bool    parse_input(int ac, char **av);
        
        int    action(int ac, char **av);
        
        std::vector<int>    fj_sort(std::vector<int> &seq, int &comparisments);
        std::deque<int>     fj_sort(std::deque<int> seq);

        void binary_insert(std::vector<int> &vec, int val, int &comp);
        void  insert_pend_jacobsthal(std::vector<int>& main, const std::vector<int>& pend, int &total_comparisons);
        std::vector<int> jacobsthal_numbers(int max_n);
        std::vector<int> jacobsthal_insertion_order(int m);
        
        //Helpers
        void    print(const std::vector<int> &a) const;
        void    print(const std::deque<int> &a) const;
};