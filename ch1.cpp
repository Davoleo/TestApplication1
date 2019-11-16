//
// Created by Davoleo on 28/09/2019.
//

// This is single-line a comment
/*
 * Multi-line Comment
 */

#include <cstdlib>      // Bunch of standard utilities
#include <iostream>     // Basic I/O
#include <limits>       // Mininum - Maximum and limits
#include <vector>       // Vectors
#include <string>       // Strings
#include <fstream>      // File I/O and String streams
#include <numeric>      // Work with Sequences of values
#include <ctime>        // Work with time
#include <cmath>        // Common Math Functions

//Available in all functions
int globalVar = 0;

int main(int argc, char** argv) {

    //Basic Hello World
    //Cout prints the text on the screen / std::endl puts a carriage return at the end
    // the "<<" operator puts the "Hello World" String in the output stream
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
    // unsigned versions (can reach double the range of the signed version but cannot store negative numbers (MIN = 0))
    // short int (at least 16 bits)
    // long int (at least 32 bits)
    // long long int (at least 64 bits)

    //floats: accurate up to 6 decimal points | they take up less memory
    float overFloat = 3.3333333;
    float overFloat2 = 3.3333333;
    //Loss Of precision
    std::printf("OverFloat Sum = %.7F\n", (overFloat + overFloat2));

    //Print Format
    //%c = char | %d = integers | %5d = integer with 5 spaces padding | %.3f = flaoting point value with precision up to the 3rd digit | %s = strings
    std::printf("%c %d %5d %.3f %s\n", 'F', 10, 5, 3.1234, "Henlo");

    std::cout << "min double: " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "max long double: " << std::numeric_limits<long double>::max() << std::endl;

    std::cout << "Favourite Number: " << overFloat << std::endl;
    std::cout << "Size of int: " << sizeof(age) << std::endl;

    //Type Inference
    auto inferredVar = true;

    std::cout << "------------------------------------------------------------" << std::endl;

    // just like the main other programming languages
    //Arithmetic Operations
    //+, -, *, /, %, --, ++
    std::cout << "5 + 2 = " << 5 + 2 << std::endl;
    std::cout << "5 - 2 = " << 5 - 2 << std::endl;
    std::cout << "5 * 2 = " << 5 * 2 << std::endl;
    std::cout << "5 / 2 = " << 5 / 2 << std::endl;
    std::cout << "5 % 2 = " << 5 % 2 << std::endl;

    //Incremental/Decremental
    int five = 5;
    std::cout << "5++ = " << five++ << std::endl;
    std::cout << "++5 = " << ++five << std::endl;
    std::cout << "5-- = " << five-- << std::endl;
    std::cout << "--5 = " << --five << std::endl;

    std::cout << "------------------------------------------------------------" << std::endl;

    //Casting
    std::cout << "4 / 5 = " << 4 / 5 << std::endl;
    std::cout << "4 / 5 = " << (float) 4 / 5 << std::endl;

    std::cout << "------------------------------------------------------------" << std::endl;

    //If Statement
    //Conditional Operators: ==, !=, >, <, >=, <=
    //Logical Operators: &&, ||, !
    bool isDrunk = false;

    if (age >= 1 && age < 18)
        std::cout << "You can't drive" << std::endl;
    else if (isDrunk)
        std::cout << "You can't drive" << std::endl;
    else if (age >= 80 && (age > 100 || age - 16 > 5))
        std::cout << "You can't drive" << std::endl;
    else
        std::cout << "You can drive" << std::endl;

    //Switch Statement
    int greetingOption = 2;

    switch (greetingOption) {
        case 1:
            std::cout << "Bounjour" << std::endl;
            break;
        case 2:
            std::cout << "Hola" << std::endl;
            break;
        case 3:
            std::cout << "Hallo" << std::endl;
            break;
        case 4:
            std::cout << "Ciao" << std::endl;
            break;
        default:
            std::cout << "Hello" << std::endl;
    }

    //Ternary Operator
    //variable = condition ? ifTrue : ifFalse
    int largestNum = 5 > 2 ? 5 : 2;

    std::cout << "------------------------------------------------------------" << std::endl;

    //Arrays: Store multiple values of the same data type in one single variable
    //Create an array of five slots
    int myColors[5];
    int badColors[5] = {0x026635, 0xFFFFFF, 0x00BFFF, 0xFF1493, 0x09493D};

    //Select single items in arrays by index
    std::cout << "1st Bad Color: " << badColors[0] << std::endl;

    //Multi-dimensional arrays
    char sampleName[2][5] = {{'M', 'a', 'r', 'i', 'o'},
                             {'R', 'o', 's', 's', 'i'}};

    //Print out the second item in the second part of the multidimensional array
    std::cout << "2nd letter in 2nd array: " << sampleName[1][1] << std::endl;

    //Change an item in a specific array slot by index
    sampleName[0][4] = 'a';
    std::cout << "New Value: " << sampleName[0][4] << std::endl;

    //When There's no errors the main function should return 0
    return 0;
}