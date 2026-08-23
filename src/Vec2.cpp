#include "Vec2.hpp"
#include <cmath>

Vec2::Vec2()
    : x(0.0), y(0.0)
{
}

Vec2::Vec2(double xIn, double yIn)
    : x(xIn), y(yIn)
{
}

Vec2 Vec2::add(const Vec2& target) const {
    return Vec2(x + target.x, y + target.y);
}

Vec2 Vec2::subtract(const Vec2& target) const{
    return Vec2(x - target.x, y - target.y);
}

Vec2 Vec2::multiply(double scalar) const{
    return Vec2(x * scalar, y * scalar);
}

double Vec2::normSquared() const {
    return x*x + y*y;
}

double Vec2::norm() const {
    return std::sqrt(normSquared());
}