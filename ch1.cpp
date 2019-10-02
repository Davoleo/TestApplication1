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

    return 0;
}