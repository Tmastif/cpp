/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:32:12 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/09 18:42:13 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iostream>

class RPN
{
    private:
        std::stack<int> _stack;

        std::string extractArg(const std::string &input, std::string::const_iterator *it);
        bool        procOperator(const std::string &arg);
        int         operation(int a, int b, const std::string &arg) const;
        bool        procNum(const std::string &arg, bool *abort);
        static bool     is_not_digit(char c);
        
        
    public:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);
        
        void    solve(const std::string &input);
        void    recurse(const std::string &input, std::string::const_iterator it);
};