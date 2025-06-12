#include "Point.hpp"

Fixed area(Point const &p1, Point const &p2, Point const &p3)
{
    // Using the determinant method for triangle area:
    // 0.5 * | x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) |
    Fixed term1 = p1.getX() * (p2.getY() - p3.getY());
    Fixed term2 = p2.getX() * (p3.getY() - p1.getY());
    Fixed term3 = p3.getX() * (p1.getY() - p2.getY());
    Fixed result = term1 + term2 + term3;

    if (result < Fixed(0))
        result = result * Fixed(-1);
    return result / Fixed(2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed totalArea = area(a, b, c);
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);

    // Check if point is strictly inside the triangle
    return (area1 > Fixed(0) && area2 > Fixed(0) && area3 > Fixed(0) &&
            (area1 + area2 + area3) == totalArea);
}
