#include "Point.hpp"

Point::Point()
    : x(0), y(0)
{

}

Point::Point(const float x, const float y)
    : x(x), y(y)
{

}

Point::~Point()
{

}

Point::Point(const Point &other)
    : x(other.x), y(other.y)
{

}

Point& Point::operator=(const Point& other)
{
    (void)other;
    return *this;
}

Fixed Point::getX() const
{
    return (x);
}

Fixed Point::getY() const
{
    return (y);
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "(" << point.getX() << "|" << point.getY() << ")";
    return (os);
}
