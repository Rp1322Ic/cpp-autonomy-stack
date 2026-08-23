#pragma once

struct Vec2 {
    double x;
    double y;

    // constructors
    Vec2();
    Vec2(double xIn, double yIn);


    Vec2 add(const Vec2& target) const;
    Vec2 subtract(const Vec2& target) const;
    Vec2 multiply(double scalar) const;
    double normSquared() const;
    double norm() const;
};