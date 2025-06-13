/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Btc.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 10:34:34 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/08 13:34:57 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Btc.h"
#include <fstream>
#include <sstream>

Btc::Btc(const std::string &dataPath, const std::string &inputPath)
 : _dataPath(dataPath), _inputPath(inputPath) {}

Btc::~Btc(void) {}

Btc::Btc(const Btc &other) : _dataPath(other._dataPath), _inputPath(other._inputPath) {}

Btc& Btc::operator=(const Btc &other)
{
    if (this != &other)
    {
        _inputPath = other._inputPath;
        _dataPath = other._dataPath;
        _input = other._input;
        _data = other._data;
    }
    return (*this);
}



//FUNCTIONS

bool   Btc::ParseData(void)
{
    std::string date;
    std::string value;
    float       temp;
    
    if (openFile(_dataFile, _dataPath))
    {
        std::getline(_dataFile, date);
        while (std::getline(_dataFile, date, ','))
        {
            std::getline(_dataFile, value, '\n');
            temp = convertToFloat(value);
            _data.insert(std::make_pair(date, temp));
        }
        _dataFile.close();
        return true;
    }
    return false;
}

bool    Btc::readInputFile(void)
{
    std::string line;
    std::string date;
    std::string value;
    
    if (openFile(_inputFile, _inputPath))
    {
        std::getline(_inputFile, line);
        while (std::getline(_inputFile, line))
        {
            size_t pos = line.find(' ');
            if (pos != std::string::npos)
            {
                date = line.substr(0, pos);
                value = line.substr(pos, std::string::npos);
                value = extractValue(value);
                _input.insert(std::make_pair(date, value));
            }
            else
                _input.insert(std::make_pair(line, " "));
        }
        _inputFile.close();
        return true;
    }
    return false;
}

std::string     Btc::extractValue(const std::string &line) const
{
    std::string value;
    size_t pos;

    pos = line.find('|');
    value = line.substr(pos + 1, std::string::npos);
    std::string::iterator it = value.begin();
    while (it != value.end() && *it == ' ')
        ++it;
    value.erase(value.begin(), it);
    return (value);
}

bool    Btc::exchange(void) const
{
    float   temp;
    std::map<std::string, float>::const_iterator iData;

    std::map<std::string, std::string>::const_iterator iInput = _input.begin();
        for (; iInput != _input.end(); ++iInput)
        {
            if (validateDate(iInput->first) && validateStringValue(iInput->second))
            {
                temp = convertToFloat(iInput->second);
                if (validateFloatValue(temp))
                {
                    iData = findCorrespondDate(iInput->first);
                    std::cout << iInput->first << " => "
                    << iInput->second << " = " << temp * iData->second << "\n";
                }
            }
            else
                std::cout << "Error: Bad input => " << iInput->first
                 << " | " << iInput->second << "\n";
        }
        return true;
}

bool    Btc::openFile(std::ifstream &file, const std::string &path)
{
    file.open(path.c_str(), std::ios::in);
    if (!file.is_open())
    {
        std::cout << "Error opening file: " << path << std::endl;
        return (false);
    }
    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "The file is empty: " << path << std::endl;
        return (false);
    }
    return (true);
}

bool    Btc::validateDate(const std::string &date) const
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

bool    Btc::validateStringValue(const std::string &value) const
{
    bool dot = false;
    std::string::const_iterator it = value.begin();

    if (value.empty())
        return false;
    for (; it != value.end(); ++it)
    {
        while (*it == ' ')
            it++;
        if (*it == '-')
            ++it;
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

bool    Btc::validateFloatValue(float value) const
{
    if (value >= 0 && value <= 1000)
        return (true);
    if (value < 0)
        std::cout << "Error: Number is negative => " << value << "\n";
    if (value > 1000)
        std::cout << "Error: too large a number => " << value << "\n";
    return (false);
}

float   Btc::convertToFloat(const std::string &value) const
{
    float result;
    std::istringstream iss(value);
    iss >> result;
    return (result);
}

std::map<std::string, float>    Btc::getData(void) const
{
    return (_data);
}

std::multimap<std::string, std::string>    Btc::getInput(void) const
{
    return (_input);
}

std::map<std::string, float>::const_iterator Btc::findCorrespondDate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator best;

    std::map<std::string, float>::const_iterator it = _data.begin();
    best = it;
    for (; it != _data.end(); ++it)
    {
        if (it->first == date)
            return (it);
        if (it->first < date && it->first > best->first)
            best = it;
    }
    return best;
}