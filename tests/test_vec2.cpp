#include "Vec2.hpp"
#include "testUtils.hpp"

#include <cassert>
#include <cmath>
#include <iostream>


void testDefaultConstructor() {
    Vec2 v;
    assert(approxEqual(v.x,0.0));
    assert(approxEqual(v.y,0.0));
}

void testConstructor() {
    Vec2 v(3.0,4.0);
    assert(approxEqual(v.x,3.0));
    assert(approxEqual(v.y,4.0));
}

void testAddition() {
    Vec2 v1(3.0,4.0);
    Vec2 v2(5.0,7.0);
    Vec2 v3 = v1.add(v2);

    assert(approxEqual(v3.x,3.0+5.0));
    assert(approxEqual(v3.y,4.0+7.0));
}

void testSubtraction() {
    Vec2 v1(3.0,4.0);
    Vec2 v2(5.0,7.0);
    Vec2 v3 = v2.subtract(v1);

    assert(approxEqual(v3.x,2.0));
    assert(approxEqual(v3.y,3.0));
}

void testMultiplication() {
    Vec2 v1(3.0,4.0);
    Vec2 v3 = v1.multiply(4.0);

    assert(approxEqual(v3.x,12.0));
    assert(approxEqual(v3.y,16.0));
}

void testNormSquared() {
    Vec2 v1(3.0,4.0);

    assert(approxEqual(v1.normSquared(),25.0));
}

void testNorm() {
    Vec2 v1(3.0,4.0);

    assert(approxEqual(v1.norm(),5.0));
}

void runVec2Tests() {
    testDefaultConstructor();
    testConstructor();
    testAddition();
    testSubtraction();
    testMultiplication();
    testNormSquared();
    testNorm();

    std::cout << "Vec2 Tests Passed!\n";
}