/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 09:56:30 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/07 14:22:04 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <fstream>

class Parser
{
    private:
        std::map<std::string, float> _map;
        std::ifstream            _dataFile;
        std::string              _dataPath;
        std::ifstream            _inputFile;
        std::string              _inputPath;
        
        
        bool        validateDate(const std::string &date);
        bool        validateStringValue(const std::string &value);
        bool        validateFloatValue(float value);
        bool        openFile(void);
        float       convertToFloat(const std::string &value);
    
    public:
        Parser(const std::string &dataPath, const std::string &inputPath);
        
        bool    ParseData(void);
        void    printMap(void) const;
        bool    readInputFile(void);
};


/*
print:
std::map<std::string, T>::iterator it;
for (it = _map.begin(); it != _map.end(); it++)
    std::cout << "Date: " << it->first << "Value: " << it->seconed << std::endl;


insert:
_map.insert(pair<std::string, T>(date, value));


*/