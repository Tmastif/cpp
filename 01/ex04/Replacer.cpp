/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:46:10 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/09 16:42:37 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>
#include <Replacer.hpp>

bool    Replacer::uploadSrcFile(char *path)
{
    filename = path;
    sourceFile.open(path, std::ios::in);
    if (!sourceFile.is_open())
    {
        std::cout << "Error opening file: " << filename << std::endl;
        return (false);
    }
    if (sourceFile.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "The file is empty: " << filename << std::endl;
        return (false);
    }
    return (true);
}

bool    Replacer::createReplaceFile(void)
{
    std::string path;

    path = filename + ".replace";
    if (!filename.empty())
    {
        replaceFile.open(path.c_str(), std::ios::out);
        if (replaceFile.is_open())
            return (true);
    }
    std::cout << "Error creating replacment file" << std::endl;
    return (false);
}

bool    Replacer::replace(std::string s1, std::string s2)
{
    std::string line;
    std::string resLine;
    size_t      pos;
    
    if (createReplaceFile())
    {
        while (std::getline(sourceFile, line))
        {
            pos = 0;
            while ((pos = line.find(s1, pos)) != std::string::npos)
            {
                resLine.append(line, 0, pos);
                resLine += s2;
                pos += s1.length();
                line = line.substr(pos);
                pos = 0;
            }
            resLine += line;
            replaceFile << resLine << "\n";
            resLine.clear();
        }
        replaceFile.close();
        return (true);
    }
    return (false);
}
 
void    Replacer::closeSrcFile(void)
{
    sourceFile.close();
}
 