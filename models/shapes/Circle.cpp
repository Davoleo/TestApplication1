//
// Created by Davoleo on 15/03/2020.
//

#include "Circle.h"
#include <cmath>

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
