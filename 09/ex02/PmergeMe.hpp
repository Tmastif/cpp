/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:59:31 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/08 13:06:47 by ilazar           ###   ########.fr       */
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
        

        //helper
        void    print_v(void);
        void    print_d(void);
};