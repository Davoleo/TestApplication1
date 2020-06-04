//
// Created by Davoleo on 15/03/2020.
//

#ifndef TESTAPPLICATION1_CIRCLE_H
#define TESTAPPLICATION1_CIRCLE_H

#include "Shape.h"

//Defining a child class (Inheritance)
class Circle : public Shape {
public:
    Circle(double radius);
    virtual ~Circle();
    double area() override;

private:

};

#endif //TESTAPPLICATION1_CIRCLE_H
