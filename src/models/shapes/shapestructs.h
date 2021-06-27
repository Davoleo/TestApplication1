//
// Created by Davoleo on 23/06/2020.
//

//VS Compiler only works with math.h and _USE_MATH_DEFINES instead of cmath
#define _USE_MATH_DEFINES
#include <math.h>

#ifndef TESTAPPLICATION1_SHAPESTRUCTS_H
#define TESTAPPLICATION1_SHAPESTRUCTS_H

#endif //TESTAPPLICATION1_SHAPESTRUCTS_H

//By Default everything inside a struct will be public unless otherwise specified
struct ShapeStruct {
    double width;
    double height;

    int id;

public:
    ShapeStruct(double width = 1, double height = 1) {
        this->width = width;
        this->height = height;
    }

    double area() {
        return width * height;
    }
};

struct CircleStruct : ShapeStruct {
    CircleStruct(double radius) {
        this->width = radius*2;
        this->height = radius*2;
    }
    double area() {
        return M_PI * pow((width/2), 2);
    }
};