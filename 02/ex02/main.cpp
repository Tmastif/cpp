/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:11:51 by ilazar            #+#    #+#             */
/*   Updated: 2025/04/25 15:11:41 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Fixed.hpp>
#include <iomanip>

void test_increment_decrement(void);
void test_comparisons(void);
void test_arithmetic(void);
void test_min_max(void);

int main( void ) 
{
    Fixed a;
    
    Fixed const     b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    
    std::cout << std::fixed << std::setprecision(8);
    test_comparisons();
    test_arithmetic();
    test_increment_decrement();
    test_min_max();
    
    return 0;
}

#include <stdexcept>

void test_comparisons(void)
{
    std::cout << "\n## Testing Comparison Operators ##\n";
    Fixed a(5.0f);
    Fixed b(10.0f);
    Fixed c(5.0f);

    std::cout << "a = " << a << ", b = " << b << ", c = " << c << "\n";
    std::cout << "a > b:  " << (a > b) << " (expected 0)\n";
    std::cout << "a < b:  " << (a < b) << " (expected 1)\n";
    std::cout << "a >= c: " << (a >= c) << " (expected 1)\n";
    std::cout << "b <= c: " << (b <= c) << " (expected 0)\n";
    std::cout << "a == c: " << (a == c) << " (expected 1)\n";
    std::cout << "a != b: " << (a != b) << " (expected 1)\n";
}

void test_arithmetic(void)
{
    std::cout << "\n## Testing Arithmetic Operators ##\n";
    Fixed a(2.5f);  // 2.5 * 256 = 640
    Fixed b(1.5f);  // 1.5 * 256 = 384
    
    // Addition
    Fixed sum = a + b;
    std::cout << "a + b: " << sum << " (expected 4.0)\n";

    // Subtraction
    Fixed diff = a - b;
    std::cout << "a - b: " << diff << " (expected 1.0)\n";

    // Multiplication
    Fixed product = a * b;
    std::cout << "a * b: " << product << " (expected 3.75)\n";

    // Division
    Fixed quotient = a / b;
    std::cout << "a / b: " << quotient << " (expected ~1.666)\n";

    // Division by zero
    try {
        Fixed zero(0.0f);
        Fixed bad = a / zero;
    } catch (const std::exception& e) {
        std::cout << "Division by zero: " << e.what() << " ✓\n";
    }
}

void test_increment_decrement()
{
    std::cout << "\n## Testing Increment/Decrement ##\n";
    Fixed a(3.0f);  // 3.0 * 256 = 768
    std::cout << "Original a: " << a << "\n";

    // Prefix increment
    std::cout << "++a: " << ++a << " (expected 3.00390625)\n";
    std::cout << "New a: " << a << "\n";

    // Postfix increment
    std::cout << "a++: " << a++ << " (returns 3.00390625)\n";
    std::cout << "New a: " << a << " (expected 3.0078125)\n";

    // Prefix decrement
    std::cout << "--a: " << --a << " (expected 3.00390625)\n";

    // Postfix decrement
    std::cout << "a--: " << a-- << " (returns 3.00390625)\n";
    std::cout << "New a: " << a << " (expected 3.0)\n";
}

void test_min_max(void)
{
    std::cout << "\n## Testing MIN/MAX ##\n";
    Fixed a(5.5f);
    Fixed b(3.3f);
    const Fixed c(2.0f);
    const Fixed d(4.0f);

    std::cout << "min(a, b): " << Fixed::min(a, b) << " (expected 3.30078125)\n";
    std::cout << "max(a, b): " << Fixed::max(a, b) << " (expected 5.5)\n";
    std::cout << "min(c, d): " << Fixed::min(c, d) << " (expected 2.0)\n";
    std::cout << "max(c, d): " << Fixed::max(c, d) << " (expected 4.0)\n";
}