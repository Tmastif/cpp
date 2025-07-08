/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:59:31 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/08 15:35:46 by ilazar           ###   ########.fr       */
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
        
        std::vector<int>    fj_sort(std::vector<int> seq);
        std::deque<int>     fj_sort(std::deque<int> seq);
        int    action(int ac, char **av);

        
        //Helpers
        void    print(const std::vector<int> &a) const;
        void    print(const std::deque<int> &a) const;
};