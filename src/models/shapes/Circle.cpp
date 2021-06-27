//
// Created by Davoleo on 15/03/2020.
//

#include "Circle.h"

//VS Compiler only works with math.h and _USE_MATH_DEFINES instead of cmath
#define _USE_MATH_DEFINES
#include <math.h>

Circle::Circle(double radius) : Shape() {
    this->radius = radius;
}

Circle::~Circle() = default;

double Circle::area() {
    return M_PI * pow(radius, 2);
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double r) {
    Circle::radius = r;
}
