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
    String() = default;

    String(const char* string)
    {
        size = strlen(string);
        //+1 to make space for the null termination char
        buffer = new char[size + 1];
        memcpy(buffer, string, size);
        buffer[size] = 0; //Adding null termination char (just to be safe)
        std::cout << "created String with size " << size << std::endl;
    }

    //Copy constructor (marking it as "= delete" will disallow copying)
    String(const String& other) : size(other.size)
    {
        buffer = new char[size + 1];
        memcpy(buffer, other.buffer, size + 1);
        //I know that the string has a null termination char since it's enforced in the other constructor
        std::cout << "copied String with size " << size << std::endl;
    }

    //Move constructor (Used to avoid copy when an RValue is passed)
    String(String&& other) noexcept : size(other.size)
    {
        //The new string points to the same buffer
        buffer = other.buffer;

        //You also need to take control of the old string making it a hollow object so that when
        //The Destructor may be called on the old object it won't delete our buffer of data
        //We've effectively moved the object to another instance without copying but just changing references
        other.size = 0;
        other.buffer = nullptr;
        std::cout << "moved String with size " << size << std::endl;
    }

    ~String(){
        delete[] buffer;
        std::cout << "deleted String with size " << size << std::endl;
    }

    void print()
    {
        for (unsigned int i = 0; i < size; i++)
            printf("%c", buffer[i]);
        std::cout << std::endl;
    }

    char& operator[](unsigned int index)
    {
        return buffer[index];
    }

    friend std::ostream& operator << (std::ostream& stream, const String& box);
};