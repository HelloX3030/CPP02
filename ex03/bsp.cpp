#include "Point.hpp"

/**
 * @brief Calculate the area of a triangle using the determinant method.
 * 
 * This function computes the area of a triangle formed by three points p1, p2, and p3.
 * The area is calculated using the determinant method:
 * 
 * Area = 0.5 * | x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) |
 * 
 * The result will always be positive since the area can't be negative, even if
 * the points are given in a clockwise orientation.
 * 
 * @param p1 First vertex of the triangle.
 * @param p2 Second vertex of the triangle.
 * @param p3 Third vertex of the triangle.
 * @return Fixed The area of the triangle.
 */
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

/**
 * @brief Check if a point is strictly inside a triangle.
 * 
 * This function checks whether a given point lies strictly inside the triangle 
 * formed by the points a, b, and c. It calculates the areas of three sub-triangles
 * formed by the point and the triangle's vertices. If all sub-triangle areas are
 * positive and their sum equals the total area of the triangle, the point is inside.
 * 
 * If any sub-triangle area is zero, the point lies on the boundary of the triangle,
 * and if any sub-triangle area is negative, the point lies outside the triangle.
 * 
 * @param a First vertex of the triangle.
 * @param b Second vertex of the triangle.
 * @param c Third vertex of the triangle.
 * @param point The point to check.
 * @return bool True if the point lies strictly inside the triangle, false otherwise.
 */
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
