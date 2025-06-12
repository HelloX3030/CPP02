#pragma once

#include "Fixed.hpp"

class Point
{
    private:
    public:
        const Fixed x;
        const Fixed y;

        // Constructors
        Point();
        Point(const float x, const float y);
        ~Point();
        Point(const Point &other);
        Point& operator=(const Point& other);
};
