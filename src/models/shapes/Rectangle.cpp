//
// Created by Davoleo on 08/04/2020.
//

#include "Rectangle.h"

Rectangle::~Rectangle() = default;

//Constructors
//builds a square
Rectangle::Rectangle(double length) {
    this->height = length;
    this->width = length;
    //   ^ The pointer operator is used to access object fields & methods
}

Rectangle::Rectangle(double height, double width) {
    this->height = height;
    this->width = width;
    //   ^ The pointer operator is used to access object fields & methods
}

// Getters and Setters -----------------
void Rectangle::setHeight(double h) {
    this->height = h;
}

double Rectangle::getHeight() {
    return height;
}

double Rectangle::getWidth() {
    return width;
}

void Rectangle::setWidth(double w) {
    this->width = w;
}

double Rectangle::area() {
    return height*width;
}
