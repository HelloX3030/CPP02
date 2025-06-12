#include "Point.hpp"
#include <iostream>

int main(void)
{
    Point a(10.2f, 33.5f);
    Point b(1.2f, 330.5f);
    Point c(100.2f, 363.5f);
    std::cout << "a" << a << " b" << b << " c" << c << std::endl;
    return 0;
}
