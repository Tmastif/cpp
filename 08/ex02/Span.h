/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:47:14 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/05 18:53:26 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdexcept>
#include <vector>

class Span
{
    private:
        unsigned int     _maxSize;
        std::vector<int> _v;
        
    public:
        Span(unsigned int N);
        Span (const Span &other);
        Span& operator=(const Span &other);
        ~Span();
        
        void    addNumber(int nbr);
        int     shortestSpan();
        int     longestSpan();
        
        template <typename Iter>
        void    multiNumbers(Iter begin, Iter end)
        {
            if (std::distance(begin, end) + _v.size() > _maxSize)
                throw std::runtime_error ("Span's space is too small");
            _v.insert(_v.end(), begin, end);
        }
};