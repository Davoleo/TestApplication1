//
// Created by Davoleo on 04/06/2020.
//

#ifndef TESTAPPLICATION1_BOX_H
#define TESTAPPLICATION1_BOX_H


#include <string>
#include <sstream>

class Box {
public:
    double height, width, depth;
    std::string boxString;

    Box() {
        this->height = 1;
        this->width = 1;
        this->depth = 1;
    }

    Box(double height, double width, double depth) {
        this->height = height;
        this->width = width;
        this->depth = depth;
    }

    //Unary Operator
    Box& operator ++ () {
        height++;
        width++;
        depth++;
        return *this;
    }

    explicit operator const char* () {
        std::ostringstream boxStream;
        boxStream << "Box: " << height << ", " << width << ", " << depth;
        boxString = boxStream.str();
        return boxString.c_str();
    }

    //Binary Operator
    Box operator + (const Box& otherBox) const {
        Box boxSum;
        boxSum.height = this->height + otherBox.height;
        boxSum.width = this->width + otherBox.width;
        boxSum.depth = this->depth + otherBox.depth;
        return boxSum;
    }

    bool operator == (const Box& otherBox) const {
        return (this->height == otherBox.height) && (this->width == otherBox.width) && (this->depth == otherBox.depth);
    }
};


#endif //TESTAPPLICATION1_BOX_H
