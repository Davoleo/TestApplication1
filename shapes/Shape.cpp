//
// Created by Davoleo on 25/02/2020.
//
// The implementation file for Shape.h
#include "Shape.h"

//Constructors
//builds a square
Shape::Shape(double length) {
    this->height = length;
    this->width = length;
    //   ^ The pointer operator is used to access object fields & methods
}

Shape::Shape(double height, double width) {
    this->height = height;
    this->width = width;
    //   ^ The pointer operator is used to access object fields & methods
}

//Deconstructor
Shape::~Shape() = default;

// Getters and Setters -----------------
void Shape::setHeight(double h) {
    this->height = h;
}

double Shape::getHeight() {
    return height;
}

double Shape::getWidth() {
    return width;
}

void Shape::setWidth(double w) {
    this->width = w;
}

double Shape::area() {
    return height*width;
}

int Shape::getCount() {
    return count;
}
