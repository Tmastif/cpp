/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:48:25 by ilazar            #+#    #+#             */
/*   Updated: 2025/07/16 18:12:46 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.h"
#include <climits>
#include <algorithm>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN &other) 
{
    if (this != &other)
    {
        _stack = other._stack;
    }
    return *this;
}
        
//FUNCTIONS

//recurse and solves the rpn, empty the stack afterwards.
void    RPN::solve(const std::string &input)
{
    if (!input.empty())
    {
        std::string::const_iterator it = input.begin();
        recurse(input, it);
    }
    else
        std::cout << "Empty string is an empty string\n";
    while (!_stack.empty())
        _stack.pop();
}

void    RPN::recurse(const std::string &input, std::string::const_iterator it)
{
    std::string     arg;
    bool            abort = false;
    
    if (it == input.end())
    {
        if (_stack.size() == 1)
        {
            std::cout << _stack.top() << std::endl;
            _stack.pop();
            return ;
        }
        else
        {
            std::cout << "Error: Expression has too many operands" << std::endl;
            return ;
        }
    }
    arg = extractArg(input, &it);
    if (procNum(arg, &abort) || (!abort && procOperator(arg)))
        recurse(input, ++it);
}

//returns a string until the first space or end of string
std::string     RPN::extractArg(const std::string &input, std::string::const_iterator *it)
{
    std::string::const_iterator space;
    
    while (*it != input.end() && *(*it) == ' ')
        ++(*it);
    space = std::find(*it, input.end(), ' ');
    std::string res(*it, space);
    *it = space - 1;
    return (res);
}

//calculates the next operator. only excepts valid operators
bool   RPN::procOperator(const std::string &arg)
{
    int     a;
    int     b;
    int     abort = false;
    
    if (arg == "+" || arg == "-" || arg == "/" || arg == "*")
    {
        if (_stack.size() < 2)
        {
            std::cout << "Error: Stack cannot apply operator: " << arg <<std::endl;
            return false;
        }
        b = _stack.top();
        _stack.pop();
        a = _stack.top();
        _stack.pop();
        int res = operation(a, b, arg, &abort);
        if (abort)
            return false;
        _stack.push(res);
        return true;
    }
    std::cout << "Error: invalid char." <<std::endl;
    return false;
}

int     RPN::operation(int a, int b, const std::string &arg, int *abort) const
{
    long long int result;
    switch (arg.at(0))
    {
        case '-':
            result = static_cast<long long>(a) - static_cast<long long>(b);
            break ;
        case '+':
            result = static_cast<long long>(a) + static_cast<long long>(b);
            break ;
        case '*':
            result = static_cast<long long>(a) * static_cast<long long>(b);
            break ;
        case '/':
            if (b == 0)
            {
                std::cout << "Error: Cannot devide by 0\n";
                *abort = true;
                return (0);
            }
            result = a / b;
        }
        if (result < INT_MIN || result > INT_MAX)
        {
            std::cout << "Error: Calculation is out of the range of int\n";
            *abort = true;
        }
        return (result);
}

//adds an operand to the stack or returns an error
bool     RPN::procNum(const std::string &arg, bool *abort)
{
    float   num;
    std::string::const_iterator start = arg.begin();
    
    if (!arg.empty())
    {
        if (*start == '-' && std::isdigit(*start + 1))
            start = arg.begin() + 1;
        if (std::find_if(start, arg.end(), is_not_digit) == arg.end())
        {
            num = std::atof(arg.c_str());
            if (num < (float)INT_MIN || num > (float)INT_MAX)
            {
                std::cout << "Error: This operand is out of int range: " << arg << std::endl;
                *abort = true;
                return false;
            }
            _stack.push(static_cast<int>(num));
            return true;
        }
    }
    return false;
}

bool     RPN::is_not_digit(char c)
{ 
    return (!std::isdigit(c));
}