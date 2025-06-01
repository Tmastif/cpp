/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:04:15 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/01 14:38:30 by ilazar           ###   ########.fr       */
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
        virtual void    printId(void) {};
        
};

#endif