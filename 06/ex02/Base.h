/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:04:15 by ilazar            #+#    #+#             */
/*   Updated: 2025/06/04 17:51:41 by ilazar           ###   ########.fr       */
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