/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:56:06 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/09 13:38:16 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"
#include <stdexcept>
#include <algorithm>
#include <climits>

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span (const Span &other) : _maxSize(other._maxSize), 
_v(other._v) {}

Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _v = other._v;
        _maxSize = other._maxSize;
    }
    return (*this);
}

Span::~Span() {}

void    Span::addNumber(int nbr)
{
    if (_v.size() >= _maxSize)
        throw std::runtime_error("Span is full");
    _v.push_back(nbr);
}

int    Span::shortestSpan()
{
    int     minSpan;
    int     temp;
    
    if (_v.size() < 2)
        throw std::runtime_error("Container has one number only");
    std::vector<int> copy = _v;
    std::sort(copy.begin(), copy.end(), std::greater<int>());
    minSpan = INT_MAX;
    for (std::vector<int>::size_type i = 0; i + 1 < copy.size(); i++)
    {
        temp = copy[i] - copy[i + 1];
        if (temp < minSpan)
            minSpan = temp;
    }
    return (minSpan);
}

int    Span::longestSpan()
{
    int     smallest = INT_MAX;
    int     largest = INT_MIN;

    if (_v.size() < 2)
        throw std::runtime_error("Container has one number only");
    for (std::vector<int>::size_type i = 0; i < _v.size(); i++)
    {
        if (_v[i] < smallest)
            smallest = _v[i];
        if (_v[i] > largest)
            largest = _v[i];
    }
    return (largest - smallest);
}
    