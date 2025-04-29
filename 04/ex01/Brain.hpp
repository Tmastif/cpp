/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:12:04 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/29 16:33:00 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain 
{
    private:
        std::string ideas[100];
        int         arr_size;
    
    public:
        Brain();
        Brain (const Brain &other);
        Brain& operator=(const Brain &other);
        ~Brain();
        
        std::string    getIdea(int nbr) const;
        void           setIdea(std::string idea, int nbr);
        void           seeIdeas(void) const;
    
};


#endif