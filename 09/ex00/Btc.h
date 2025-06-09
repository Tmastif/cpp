/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Btc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 09:56:30 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/08 13:30:59 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <fstream>

class Btc
{
    private:
        std::map<std::string, float>             _data;
        std::multimap<std::string, std::string>  _input;
        std::ifstream                _dataFile;
        std::string                  _dataPath;
        std::ifstream                _inputFile;
        std::string                  _inputPath;
        
        
        bool        validateDate(const std::string &date) const;
        bool        validateStringValue(const std::string &value) const;
        bool        validateFloatValue(float value) const;
        bool        openFile(std::ifstream &file, const std::string &path);
        float       convertToFloat(const std::string &value) const;
        std::map<std::string, float>::const_iterator findCorrespondDate(const std::string &date) const;
        std::string     extractValue(const std::string &line) const;
    
    public:
        //constructors destructors
        Btc(const std::string &dataPath, const std::string &inputPath);
        ~Btc();
        Btc(const Btc &other);
        Btc& operator=(const Btc &other);
        
        //functions
        bool    ParseData(void);
        bool    readInputFile(void);
        bool    exchange(void) const;
        std::map<std::string, float>                 getData(void) const;
        std::multimap<std::string, std::string>      getInput(void) const;
        
        template <typename MapType>
        void    printMap(const MapType &container) const
        {
            typename MapType::const_iterator it = container.begin();
            for (; it != container.end(); ++it)
            {
                std::cout << it->first << " " << it->second << std::endl;
            }
        }
};
