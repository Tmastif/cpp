/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:04:15 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/17 15:44:09 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
#define BASE_H

class Base
{
    public:
        virtual ~Base();

        Base *          generate(void);
        void            identify(Base* p);
        void            identify(Base& p);
};

#endif

/*
dynamic cast can be used when we have a polymorphic base class
(class that has at least one virtual function).
*/