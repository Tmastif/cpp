/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:31:17 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/01 12:25:24 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>

class ScalarConverter
{
    private:
        ScalarConverter() {};
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter &other);
        
        //helper functions
        static bool    specialCases(const std::string &literal);
        static bool    isChar(const std::string &literal);
        static bool    isInt(const std::string &literal);
        static bool    isFloat(const std::string &literal);
        static bool    isDouble(const std::string &literal);
        static void    printConversions(int i);
        static void    printConversions(float f);
        static void    printConversions(double d);
        
        public:
        ~ScalarConverter() {};
        
        static void convert(const std::string &literal);
};

/* 
- the destructor is redundant but mentioned to fit the rules
it is public as recommended practice to avoid possible issues with inheritance.

static function:
- no object required for calling it
- no access to non-static variables/methods
- no 'this' pointer */

#endif