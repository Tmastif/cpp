/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:48:25 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/09 18:54:23 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.h"
#include <climits>
#include <algorithm>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) { (void)other; }

RPN& RPN::operator=(const RPN &other) 
{
    (void)other;
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

//returns a string made of iterator until first space or end of string
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
        _stack.push(operation(a, b, arg));
        return true;    
    }
    std::cout << "Error: invalid char." <<std::endl;
    return false;
}

int     RPN::operation(int a, int b, const std::string &arg) const
{
    switch (arg.at(0))
    {
        case '-':
            return(a - b);
        case '+':
            return(a + b);
        case '*':
            return(a * b);
        case '/':
            return(a / b);
        default:
            std::cout << "Error: operation\n";
        return (0);
    }
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
            if (num < INT_MIN || num > INT_MAX)
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