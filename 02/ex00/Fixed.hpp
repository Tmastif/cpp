/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:09:59 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/25 15:04:32 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
private:
    int              _width;
    static const int _bits = 8;

public:
    Fixed();
    Fixed(const Fixed& original);
    Fixed& operator=(const Fixed& original);
    ~Fixed();

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

#endif