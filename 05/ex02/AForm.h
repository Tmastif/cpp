/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:15:40 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/26 19:37:46 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include <ostream>

class Bureaucrat;

class AForm
{
    protected:
        std::string const _name;
        bool _isSigned;
        int const _signGrade;
        int const _executeGrade;

    public:
        static const int lowestGrade = 150;
        static const int highestGrade = 1;
        
        AForm(const std::string &name, int signGrade, int excuteGrade);
        AForm(const AForm &other);
        AForm& operator=(const AForm &other);
        ~AForm();
        
        std::string getName(void) const;
        bool            getIsSigned(void) const;
        int             getSignGrade(void) const;
        int             getExecuteGrade(void) const;
        void            beSigned(const Bureaucrat &b);
        void            execute(Bureaucrat const &executor) const;
        virtual void    exeAction(void) const = 0;
        
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

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Form is not signed");
                }
        };
};

std::ostream& operator<<(std::ostream &os, const AForm &form);

#endif