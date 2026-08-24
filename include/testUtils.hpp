#pragma once
#include <cmath>

inline bool approxEqual(double a, double b, double tolerance = 1e-6) {
    return std::abs(a - b) < tolerance;
}