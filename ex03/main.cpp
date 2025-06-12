#include "Point.hpp"
#include <iostream>

int main(void)
{
    Point a(10.2f, 33.5f);
    Point b(1.2f, 330.5f);
    Point c(100.2f, 363.5f);
    Point p(34, 343);
    std::cout << std::boolalpha;
    std::cout << "a" << a << " b" << b << " c" << c << " p" << p << std::endl;
    std::cout << "in Triangle: " << bsp(a, b, c, p) << std::endl;
    return 0;
}
