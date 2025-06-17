/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:31:17 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/17 15:12:40 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cmath>
#include <cerrno>


void ScalarConverter::convert(const std::string &literal)
{
    if (specialCases(literal))
        return ;
    if (isChar(literal))
        return ;
    if (isInt(literal))
    {
        int i = atoi(literal.c_str());
        printConversions(i);
        return ;
    }
    if (isFloat(literal))
    {
        std::string num = literal.substr(0, literal.length() - 1);
        float f = static_cast<float>(strtod(num.c_str(), NULL));
        printConversions(f);
        return ;
    }
    if (isDouble(literal))
    {
        double d = strtod(literal.c_str(), NULL);
        printConversions(d);
        return ;
    }
}

void ScalarConverter::printConversions(double d)
{
    if (d < CHAR_MIN || d > CHAR_MAX || std::isnan(d) || std::isinf(d))
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<char>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    if (d < INT_MIN || d > INT_MAX || std::isnan(d) || std::isinf(d))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    float f = static_cast<float>(d);
    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    std::cout << "double: " << d;
    if (d == static_cast<int>(d))
        std::cout << ".0" << std::endl;
    else
        std::cout << "\n";
}

bool ScalarConverter::isDouble(const std::string &s)
{
    if (s.empty())
        return false;
    char* endptr;
    strtod(s.c_str(), &endptr);
    return (endptr == s.c_str() + s.length() && s != "." && s != "-" && s != "+");
}

void ScalarConverter::printConversions(float f)
{
    const float max_safe = 2147483520.0f;
    const float min_safe = -2147483648.0f;

    if (f < CHAR_MIN || f > CHAR_MAX || std::isnan(f) || std::isinf(f))
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<char>(f)))
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

    if (f < min_safe || f > max_safe || std::isnan(f) || std::isinf(f))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;

    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f);
    if (f == static_cast<int>(f))
        std::cout << ".0" << std::endl;
    else
        std::cout << "\n";
}

bool ScalarConverter::isFloat(const std::string &s)
{
    if (s.empty() || s[s.length() - 1] != 'f')
        return false;
    std::string num = s.substr(0, s.length() - 1);
    char* endptr;
    strtod(num.c_str(), &endptr);
    return (endptr == num.c_str() + num.length() && num != "." && !num.empty() && num != "-" && num != "+");
}

void ScalarConverter::printConversions(int i)
{
    if (i < CHAR_MIN || i > CHAR_MAX)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<char>(i)))
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

bool ScalarConverter::isInt(const std::string &literal)
{
    if (literal.empty() || literal == "-" || literal == "+")
        return false;
    char *endptr;
    errno = 0;
    long val = strtol(literal.c_str(), &endptr, 10);
    if (endptr != literal.c_str() + literal.length())
        return false;
    if (errno == ERANGE || val < INT_MIN || val > INT_MAX)
        return false;
    return true;
}

bool ScalarConverter::isChar(const std::string &literal)
{
    char    c;
    
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
    {
        c = literal[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return (true);
    }
    return (false);
}
/*
inf - infinite
nan - not a numer (not a valid number)
inff/nanf - same for float
*/
bool ScalarConverter::specialCases(const std::string &literal)
{
    float       f;
    double      d;
    std::string charInt = "char: impossible\nint: impossible\n";
    
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
    {
        std::cout << charInt;
        if (literal == "-inff")
            f = -std::numeric_limits<float>::infinity();
        else if (literal == "+inff")
            f = std::numeric_limits<float>::infinity();
        else
            f = std::numeric_limits<float>::quiet_NaN();
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
        return (true);
    }
    else if (literal == "-inf" || literal == "+inf" || literal == "nan")
    {
        std::cout << charInt;
        if (literal == "-inf")
            d = -std::numeric_limits<double>::infinity();
        else if (literal == "+inf")
            d = std::numeric_limits<double>::infinity();
        else
            d = std::numeric_limits<double>::quiet_NaN();
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return (true);
    }
    return (false);
}




ScalarConverter::ScalarConverter(const ScalarConverter &other) 
{
    (void) other;
}


ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
    (void) other;
    return (*this);
};