/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:01:31 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/27 11:49:43 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include "AForm.h"

class Intern
{
    public:
        Intern();
        Intern(const Intern &other);
        Intern& operator=(const Intern &other);
        ~Intern();
        
        AForm*    makeForm(const std::string &name, const std::string &target);
        void      toUpper(std::string &str);
};

AForm* createShrubbery(const std::string &target);
AForm* createRobotomy(const std::string &target);
AForm* createPresidential(const std::string &target);

#endif