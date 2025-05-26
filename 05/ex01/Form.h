/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:15:40 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/26 15:55:46 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <ostream>

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool _isSigned;
        int const _signGrade;
        int const _executeGrade;

    public:
        static const int lowestGrade = 150;
        static const int highestGrade = 1;
        
        Form(const std::string &name, int signGrade, int excuteGrade);
        Form(const Form &other);
        Form& operator=(const Form &other);
        ~Form();
        
        std::string getName(void) const;
        bool        getIsSigned(void) const;
        int         getSignGrade(void) const;
        int         getExecuteGrade(void) const;
        void        beSigned(const Bureaucrat &b);
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Form: Grade is too high");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Form: Grade is too low");
                }
        };
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif