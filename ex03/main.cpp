#include "Point.hpp"
#include <iostream>

int main(void)
{
    std::cout << std::boolalpha;

    {
        Point a(0.0f, 0.0f), b(10.0f, 0.0f), c(5.0f, 10.0f), p(5.0f, 5.0f);
        std::cout << "Test 1 - Inside: " << bsp(a, b, c, p) << std::endl;
    }

    {
        Point a(0.0f, 0.0f), b(10.0f, 0.0f), c(5.0f, 10.0f), p(20.0f, 5.0f);
        std::cout << "Test 2 - Outside: " << bsp(a, b, c, p) << std::endl;
    }

    {
        Point a(0.0f, 0.0f), b(10.0f, 0.0f), c(5.0f, 10.0f), p(5.0f, 0.0f);
        std::cout << "Test 3 - On Edge: " << bsp(a, b, c, p) << std::endl;
    }

    return 0;
}
