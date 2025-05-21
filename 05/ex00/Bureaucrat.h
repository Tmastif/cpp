/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 11:29:27 by ilazar            #+#    #+#             */
/*   Updated: 2025/05/21 15:41:50 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat
{
    private:
        std::string const _name;
        int               _grade;

    public:
        static const int lowestGrade = 150;
        static const int highestGrade = 1;

        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName(void) const;
        int         getGrade(void) const;
        void        incGrade(void);
        void        decGrade(void);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Bureaucrat: Grade is too high");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Bureaucrat: Grade is too low");
                }
        };

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bur);

#endif