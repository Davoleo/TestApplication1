//
// Created by Davoleo on 04/06/2020.
//

#ifndef TESTAPPLICATION1_BOX_H
#define TESTAPPLICATION1_BOX_H

#include <string>
#include <sstream>

class Box {
private:
    double height;
    double width;
    double depth;
    std::string boxName;

public:
    Box() {
        height = 1;
        width = 1;
        depth = 1;
        boxName = "Unknown";
    }

    //Copy Constructor
    Box(const Box& other) : height(other.height), width(other.width), depth(other.depth), boxName(other.boxName) {
        std::cout << "Box Copy!" << std::endl;
    }

    //Member initializer Lists
    //Should always be in the same order as their declaration
    //This also optimizes code in case of non primitive variable initialization because otherwise objects are initialized twice
    //(once with the default constructor and the second time with the constructor you call)
    Box(double size) : height(size), width(size), depth(size), boxName("Unknown") // NOLINT(google-explicit-constructor)
    {}

    //The explicit keyword disables the default behaviour of implicit calls to constructors
    explicit Box(const char* name) : height(1), width(1), depth(1), boxName(name)
    {}

    //The meaning of THIS:
    //'this' is a pointer to the current object instance that the method belongs to
    //it's only usable in non-static method of course
    Box(double height, double width, double depth, const char* name) {
        Box* box = this;

        this->height = height;
        this->width = width;
        this->depth = depth;
        box->boxName = name;
    }

    const std::string &getBoxName() const {
        return boxName;
    }

    double getHeight() const {
        return height;
    }

    double getWidth() const {
        return width;
    }

    double getDepth() const {
        return depth;
    }

    //Unary Operator
    Box& operator ++ () {
        height++;
        width++;
        depth++;
        return *this;
    }

    //Binary Operator
    Box operator + (const Box& otherBox) const {
        Box boxSum;
        boxSum.height = this->height + otherBox.height;
        boxSum.width = this->width + otherBox.width;
        boxSum.depth = this->depth + otherBox.depth;
        return boxSum;
    }

    Box operator * (const Box& multiplierBox) const {
        Box result;
        result.height = this->height * multiplierBox.height;
        result.width = this->width * multiplierBox.width;
        result.depth = this->depth * multiplierBox.depth;
        return result;
    }

    bool operator == (const Box& otherBox) const {
        return (height == otherBox.height) && (width == otherBox.width) && (depth == otherBox.depth);
    }

    bool operator != (const Box& otherBox) const {
        return !(*this == otherBox);
    }
};


#endif //TESTAPPLICATION1_BOX_H
