//
// Created by Davoleo on 05/08/2020.
//

#ifndef TESTAPPLICATION1_PRINTABLE_H
#define TESTAPPLICATION1_PRINTABLE_H

#include <string>

//Interface that contains a pure virtual method
//If you don't implement this method in a sub-class you won't be able to instantiate it
class Printable {
public:
    virtual std::string getClassName() = 0;
};

#endif //TESTAPPLICATION1_PRINTABLE_H
