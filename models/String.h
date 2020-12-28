//
// Created by Davoleo on 28/12/2020.
//
#include <cstring>

#ifndef TESTAPPLICATION1_STRING_H
#define TESTAPPLICATION1_STRING_H

#endif //TESTAPPLICATION1_STRING_H

class String {
private:
    char* buffer;
    unsigned int size;

public:
    String(const char* string)
    {
        size = strlen(string);
        //+1 to make space for the null termination char
        buffer = new char[size + 1];
        memcpy(buffer, string, size);
        buffer[size] = 0; //Adding null termination char (just to be safe)
    }

    //Copy constructor (marking it as "= delete" will disallow copying)
    String(const String& other) : size(other.size)
    {
        buffer = new char[size + 1];
        memcpy(buffer, other.buffer, size + 1);
        //I know that the string has a null termination char since it's enforced in the other constructor
    }

    ~String(){
        delete[] buffer;
    }

    char& operator[](unsigned int index)
    {
        return buffer[index];
    }

    friend std::ostream& operator << (std::ostream& stream, const String& box);
};