/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:46:10 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/09 15:33:03 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <fstream>
#include <string>
#include <iostream>

class Replacer
{
    private:
        
        std::string  filename;
        std::fstream sourceFile;
        std::fstream replaceFile;
        
        bool createReplaceFile(void);
        
        
    public:

        bool    uploadSrcFile(char *path);
        bool    replace(std::string s1, std::string s2);
        void    closeSrcFile(void);
};

#endif