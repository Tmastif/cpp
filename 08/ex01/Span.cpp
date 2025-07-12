/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:56:06 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/12 08:06:29 by ilazar           ###   ########.fr       */
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
    int     smallest;
    int     largest;

    if (_v.size() < 2)
        throw std::runtime_error("Container has one number only");
    std::vector<int>::iterator max = std::max_element(_v.begin(), _v.end());
    std::vector<int>::iterator min = std::min_element(_v.begin(), _v.end());
    largest = *max;
    smallest = *min;
    return (largest - smallest);
}


bool    Span::has(int nbr)
{
    if (std::find(_v.begin(), _v.end(), nbr) != _v.end())
        return true;
    return false;  
};