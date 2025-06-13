/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:58:49 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/06 21:53:51 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <deque>
#include <stack>


template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
    
        typename Container::iterator           begin();
        typename Container::const_iterator     begin() const;
        typename Container::iterator           end();
        typename Container::const_iterator     end() const;
};

#include "MutantStack.tpp"