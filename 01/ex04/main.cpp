/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:37:19 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/09 16:16:12 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>
#include <Replacer.hpp>

int     main(int ac, char **av)
{
    Replacer file;
    
    if (ac != 4)
    {
        std::cout << "The program excepts 3 parameters only\n";
        return (1);
    }

    if (file.uploadSrcFile(av[1]))
    {
        if (file.replace(av[2], av[3]))
        {
            file.closeSrcFile();
            return (0);
        }    
    }
    return(1);
}



