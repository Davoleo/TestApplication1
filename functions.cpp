//
// Created by Davoleo on 23/06/2020.
//

#include <iostream>
#include "models/shapes/Shape.h"
#include "log.h"

//Function definition  (we declared the signature and defined the body)
int Multiply(int a, int b) {
    Log("Multiply");
    return a * b;
}

void Log(const char* message) {
std::cout << message << std::endl;
}

//Custom Functions, Defining a function - parameters can be assigned custom values
double AddNumbers(double num1 = 0, double num2 = 0) {
    return num1 + num2;
}

void AssignAge(int age) {
    //variables inside of functions are local variable, they can't be accessed out of the function body
    age = 24;
}

void assignAge2(int* pAge) {
    //Assigns a value to the pAge address
    *pAge = 22;
}

void DoubleArray(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = arr[i] * 2;
    }
}

//Accepts every a shape or its subclasses
void printArea(Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl;
}