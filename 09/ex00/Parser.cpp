/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 10:34:34 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/07 14:18:26 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"
#include <fstream>
#include <sstream>

Parser::Parser(const std::string &dataPath, const std::string &inputPath)
 : _dataPath(dataPath), _inputPath(inputPath) {}


//FUNCTIONS

bool   Parser::ParseData(void)
{
    std::string date;
    std::string value;
    float       temp;
    
    if (openFile())
    {
        std::getline(_dataFile, date); //first line
        while (std::getline(_dataFile, date, ','))
        {
            std::getline(_dataFile, value, '\n');
            if (validateStringValue(value) && validateDate(date))
            {
                temp = convertToFloat(value);
                if (validateFloatValue(temp))
                    _map.insert(std::make_pair(date, temp));
            }
            else
                std::cout << "Error: Bad input => " << date << " " << value << "\n";
        }
        _dataFile.close();
    }
    return (true);
}

void    Parser::printMap(void) const
{
    std::map<std::string, float>::const_iterator it = _map.begin();
    for (; it != _map.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

// bool    Parser::insert(const std::string &date, float value)
// {
//         std::cout << "valid everything!" << "\n";
//         // _map.insert(std::make_pair(date, value));
//         return true;
// }

bool    Parser::openFile(void)
{
    _dataFile.open(_dataPath.c_str(), std::ios::in);
    if (!_dataFile.is_open())
    {
        std::cout << "Error opening file: " << _dataPath << std::endl;
        return (false);
    }
    if (_dataFile.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "The file is empty: " << _dataPath << std::endl;
        return (false);
    }
     std::cout << "opened file\n";
    return (true);
}

bool    Parser::validateDate(const std::string &date)
{
    int year;
    int month;
    int day;
    int makaf = 0;

    std::string::const_iterator it = date.begin();
    for (; it != date.end(); ++it)
    {
        if (!std::isdigit(*it))
        {
            if (*it == '-')
            {
                makaf++;
                if (makaf > 2)
                    return false;
            }
            else
                return false;
        }
    }
    std::istringstream iss(date);   
    iss >> year;
    iss >> month;
    iss >> day;

    // std::cout << "y: " << year << "\n";
    // std::cout << "m: " << month << "\n";
    // std::cout << "d: " << day << "\n";

    if (day >= 0 || month >= 0)
    {
        return false;
    }
    month *= -1;
    day *= -1;
    if (year > 0 && year < 9999)
    {    
        if (month <= 12)
        {
            if (day <= 31)
                return true;
        }       
    }
    return false;
}

bool    Parser::validateStringValue(const std::string &value)
{
    bool dot = false;
    std::string::const_iterator it = value.begin();

    if (value.empty() || !std::isdigit(*it))
        return false;
            
    for (; it != value.end(); ++it)
    {
        if (!std::isdigit(*it))
        {
            if (*it == '.' && it != (value.end() - 1))
            {
                if (dot == true)
                    return false;
                dot = true; 
            }
            else
                return false;
        }
    }
    return true;
}

bool    Parser::validateFloatValue(float value)
{
    if (value >= 0 && value <= 1000)
        return (true);
    if (value < 0)
        std::cout << "Error: Number is negative =>" << value << "\n";
    if (value > 1000)
        std::cout << "Error: too large a number => " << value << "\n";
    return (false);
}

float   Parser::convertToFloat(const std::string &value)
{
    float result;
    std::istringstream iss(value);
    iss >> result;
    return (result);
}