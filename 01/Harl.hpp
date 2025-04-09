/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:51:10 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/09 16:54:23 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
private:
    
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);

public:

    void    complain(std::string level);

};

#endif
