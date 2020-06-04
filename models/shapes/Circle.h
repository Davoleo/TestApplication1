//
// Created by Davoleo on 15/03/2020.
//

#ifndef TESTAPPLICATION1_CIRCLE_H
#define TESTAPPLICATION1_CIRCLE_H

#include "Shape.h"

//Defining a child class (Inheritance)
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius);
    virtual ~Circle();
    double area() override;
    double getRadius() const;
    void setRadius(double radius);

private:

};

#endif //TESTAPPLICATION1_CIRCLE_H
