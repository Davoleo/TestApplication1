//
// Created by Davoleo on 25/02/2020.
//

//Make sure we don't load more than one header
#ifndef TESTAPPLICATION1_SHAPE_H
#define TESTAPPLICATION1_SHAPE_H

class Shape {

//Accessible to anything that has access to the object
public:
    //static field: shared between different objects, property of the class
    static int count;

    //Deconstructor - Called anytime the object is deleted or not used anymore
    virtual ~Shape();

    //Implementing in Shape.cpp doesn't work :(
    static int getCount() {
        return count;
    }

    //Marked as virtual because it's not defined in the Shape class but defined in its child classes
    //The fact this is an abstract class is defined by "= 0"
    virtual double area() = 0;

//Accessible inside of the class itself and from child classes
protected:

//Accessible only inside of the class itself
private:

};


#endif //TESTAPPLICATION1_SHAPE_H
