//
// Created by Davoleo on 15/03/2020.
//

#include "Circle.h"
#include <cmath>

Circle::Circle(double radius) : Shape(radius * 2) {
}

Circle::~Circle() = default;

double Circle::area() {
    return M_PI * pow((width / 2), 2);
}
