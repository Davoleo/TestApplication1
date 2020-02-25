//
// Created by Davoleo on 25/02/2020.
//

#ifndef TESTAPPLICATION1_SHAPE_H
#define TESTAPPLICATION1_SHAPE_H


class Shape {

//Accessible to anything that has access to the object
public:
    //static field: shared between different objects, property of the class
    static int count;

    //Constructors: Create the object
    Shape();

    Shape(double length);

    Shape(double height, double width);

    //Deconstructor - Called anytime the object is deleted or not used anymore
    virtual ~Shape();

    //Getters & Setters
    double getHeight();

    void setHeight(double height);

    double getWidth();

    void setWidth(double width);

    static int getCount();

    //Marked as virtual because it's not defined in the Shape class but defined in its child classes
    virtual double area();

//Accessible inside of the class itself and from child classes
protected:
    double height;
    double width;

//Accessible only inside of the class itself
private:

};


#endif //TESTAPPLICATION1_SHAPE_H
