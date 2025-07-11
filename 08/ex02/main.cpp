/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:45:23 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/20 14:26:45 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.h"
#include <list>
#include <algorithm>

void    test_find(void);
void    test_const(void);
void    test_empty_stack(void);
void    pdf_test_ms(void);
void    pdf_test_list(void);

int main(void)
{
    pdf_test_list();
    pdf_test_ms();
    // test_empty_stack();
    // test_const();
    // test_find();

    return 0;
}

void    test_empty_stack(void)
{
    MutantStack<int> empty_stack;
    if (empty_stack.begin() == empty_stack.end())
    std::cout << "Empty stack: begin() == end()" << std::endl;
}

void    test_const(void)
{
    MutantStack<int> mstack;
    std::cout << "Test const:" << std::endl;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    const MutantStack<int> const_mstack = mstack;
    MutantStack<int>::const_iterator cit = const_mstack.begin();
    while (cit != const_mstack.end())
    {
        std::cout << *cit << std::endl;
        ++cit;
    }
    // *cit = 40; - won't compile, because of const
}

void    test_find(void)
{
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);

    MutantStack<int>::iterator it = std::find(mstack.begin(), mstack.end(), 20);
    if (it != mstack.end())
        std::cout << "Found 20 at position: " << std::distance(mstack.begin(), it) << std::endl;
    else
        std::cout << "20 not found" << std::endl;
}

void    pdf_test_ms(void)
{
    std::cout << "Test with MutantStack: " << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

void    pdf_test_list(void)
{
    std::cout << "Test with list: " << std::endl;
    std::list<int> list;

    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}