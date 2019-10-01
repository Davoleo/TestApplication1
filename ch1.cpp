//
// Created by Davoleo on 28/09/2019.
//

// This is single-line a comment
/*
 * Multi-line Comment
 */

#include <iostream>     // Basic I/O
#include <vector>       // Vectors
#include <string>       // Strings
#include <fstream>      // File I/O


int main() {

    //Basic Hello World
    //Cout prints the text on the screen / std::endl puts a carriage return at the end
    std::cout << "Hello World" << std::endl;

    //Data types
    // Constant double value (can contain decimal points) | Accurate up to 15 digits
    const double PI = 3.1415926535;
    // Other double
    // long double

    //Contains just one character | 1 byte | enclosed in single quotes
    char epicChar = 'K';
    //booleans
    bool sampleBool = true;
    //integers
    int age = 18;
    // Other ints
    // short int (at least 16 bits)
    // long int (at least 32 bits)
    // long long int (at least 64 bits)
    //unsigned int (Same size as regular int but double range on one side)

    //floats: accurate up to 6 decimal points | they take up less memory
    float sampleFloat = 3.33;

    std::cout << "Favourite Number: " << sampleFloat << std::endl;
    std::cout << "Size of int: " << sizeof(age) << std::endl;

    return 0;
}