#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    // Fixed a;
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "--- Constructors and Basic Output ---" << std::endl;
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a after ++: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a after a++: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
    std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;

    std::cout << "\n--- Arithmetic Operators ---" << std::endl;
    Fixed c(10);
    Fixed d(2.5f);
    std::cout << "c: " << c << ", d: " << d << std::endl;
    std::cout << "c + d: " << (c + d) << std::endl;
    std::cout << "c - d: " << (c - d) << std::endl;
    std::cout << "c * d: " << (c * d) << std::endl;
    std::cout << "c / d: " << (c / d) << std::endl;

    std::cout << "\n--- Comparison Operators ---" << std::endl;
    Fixed e(5.5f);
    Fixed f(5.5f);
    Fixed g(4.25f);
    std::cout << std::boolalpha;
    std::cout << "e: " << e << ", f: " << f << ", g: " << g << std::endl;
    std::cout << "e == f: " << (e == f) << std::endl;
    std::cout << "e != g: " << (e != g) << std::endl;
    std::cout << "g < e: " << (g < e) << std::endl;
    std::cout << "g <= e: " << (g <= e) << std::endl;
    std::cout << "e >= f: " << (e >= f) << std::endl;
    std::cout << "g > f: " << (g > f) << std::endl;

    std::cout << "\n--- Conversion Functions ---" << std::endl;
    Fixed h(42.42f);
    std::cout << "h: " << h << std::endl;
    std::cout << "h.toInt(): " << h.toInt() << std::endl;
    std::cout << "h.toFloat(): " << h.toFloat() << std::endl;

    std::cout << "\n--- Increment/Decrement ---" << std::endl;
    Fixed i;
    std::cout << "i: " << i << std::endl;
    std::cout << "++i: " << ++i << std::endl;
    std::cout << "i++: " << i++ << std::endl;
    std::cout << "i: " << i << std::endl;
    std::cout << "--i: " << --i << std::endl;
    std::cout << "i--: " << i-- << std::endl;
    std::cout << "i: " << i << std::endl;
    return 0;
}
