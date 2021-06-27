//
// Created by Davoleo on 08/04/2020.
//

#ifndef TESTAPPLICATION1_RECTANGLE_H
#define TESTAPPLICATION1_RECTANGLE_H


#include "Shape.h"

class Rectangle : public Shape {

public:

    //Constructors: Create the object
    Rectangle(double size);

    Rectangle(double height, double width);

    virtual ~Rectangle();

    //Getters & Setters for private/protected properties
    double getHeight();

    void setHeight(double height);

    double getWidth();

    void setWidth(double width);

    double area() override;

    std::string getClassName() override {
        return "Player";
    }

protected:
    double height;
    double width;

};


#endif //TESTAPPLICATION1_RECTANGLE_H
