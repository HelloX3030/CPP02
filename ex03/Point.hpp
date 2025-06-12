#pragma once

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;

    public:
        // Constructors
        Point();
        Point(const float x, const float y);
        ~Point();
        Point(const Point &other);
        Point& operator=(const Point& other);

        // Functions
        Fixed getX() const;
        Fixed getY() const;
};

std::ostream& operator<<(std::ostream& os, const Point& point);

bool bsp( Point const a, Point const b, Point const c, Point const point);
