//
// Created by Davoleo on 25/02/2020.
//

//Make sure we don't load more than one header
#ifndef TESTAPPLICATION1_SHAPE_H
#define TESTAPPLICATION1_SHAPE_H

#include "Printable.h"

class Shape : Printable {

//Accessible to anything that has access to the object
public:
    //static field: shared between different objects, property of the class
    static int count;

    //Destructor - Called anytime the object is deleted or not used anymore
    //Virtual Destructors
    //Destructors should be marked as virtual if the class is going to be extended, because
    //In case of a polymorphic object creation (e.g. Shape* shape = new Rectangle(); delete shape;)
    //The destructor of the derived class Rectangle is not called automatically and could create memory leaks if Rectangle did some heap allocation
    virtual ~Shape() = default;

    //Implementing in Shape.cpp doesn't work :(
    static int getCount() {
        return count;
    }

    //Marked as virtual because it can be overridden by subclasses
    //Virtual functions come with the runtime cost of creating the VTable that links methods to the overridden version at runtime (memory)
    //and that you're also always going through the VTable to know what method to call
    //Setting the function equals to 0 makes it not implemented which means it becomes mandatory for subclasses to override it and implement it
    virtual double area() = 0;

    std::string getClassName() override {
        return "Shape";
    }

//Accessible inside of the class itself and from child classes
protected:

//Accessible only inside of the class itself
private:

};


#endif //TESTAPPLICATION1_SHAPE_H
