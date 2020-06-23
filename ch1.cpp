//
// Created by Davoleo on 28/09/2019.
//

// This is single-line a comment
/*
 * Multi-line Comment
 */

//What begins with a # is a preprocess statement (they are read before actual code compilation)
//Include takes everything that is inside of the linked header files and puts them into the main file (literally copy and paste lul)
#include <cstdlib>      // Bunch of standard utilities
#include <iostream>     // Basic I/O - For example cout cin that output to the console
#include <limits>       // Mininum - Maximum and limits
#include <vector>       // Vectors
#include <array>        // C++ arrays
#include <string>       // Strings
#include <fstream>      // File I/O and String streams
#include <numeric>      // Work with Sequences of values
#include <ctime>        // Work with time
#include <cmath>        // Common Math Functions
#include <sstream>      // String Streams

//Creates an alias for something
#define INTEGER int

#include "log.h"
#include "models/shapes/Shape.h"
#include "models/Box.h"
#include "models/shapes/Rectangle.h"
#include "models/shapes/Circle.h"

//Available in all functions
INTEGER globalVar = 0;

//By Default everything inside a struct will be public unless otherwise specified
struct ShapeStruct {
    double width, height;

    ShapeStruct(double width = 1, double height = 1) {
        this->width = width;
        this->height = height;
    }

    double area() {
        return width * height;
    }

private:
    int id;
};

struct CircleStruct : ShapeStruct {
    CircleStruct(double radius) {
        this->width = radius*2;
        this->height = radius*2;
    }
    double area() {
        return M_PI * pow((width/2), 2);
    }
};

//function declaration (only the signature)
//This declaration is wired up to the real definition by the linker
int Multiply(int a, int b);

//First function executed at runtime line-by-line
//Every cpp file is compiled to a .obj file (by the compiler)
//All the .obj files are archived together into an .exe file by the linker
int main(int argc, char** argv) {

    //#if preprocess statements include or exclude some code whether the condition is true or false
#if 1
    std::cout << "Conditioned code" << std::endl;
#endif

    //Basic Hello World
    //Cout prints the text on the screen / std::endl puts a carriage return at the end
    // the "<<" operator puts the "Hello World" String in the output stream
    // << is an overloaded operator (just like a function that is called on cout)
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
    int age;
    std::cout << "ENTER YOUR FUCKING AGE! ";
    //Captures user input
    std::cin >> age;
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
    //Automatically becomes a char* variable (needs to be converted to a string before using it like one)
    auto inferredVar = 1231;
    std::string emptyString = "123";

    //stoi() converts a String to an Integer
    int n = stoi(emptyString);

    std::cout << "------------------------------------------------------------" << std::endl;

    Log("Test");
    std::cout << Multiply(5, 8) << std::endl;

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
    bool canVote = age >= 18 ? true : false;
    std::cout.setf(std::ios::boolalpha);
    std::cout << "can you vote? " << canVote << std::endl;

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

    std::cout << "------------------------------------------------------------" << std::endl;

    //Vectors
    //Dynamic Arrays (used when you don't know how many items you're going to store)
    std::vector<int> numVector(2);
    numVector[0] = 1;
    numVector[1] = 2;
    //Adds an item to the end of the vector
    numVector.push_back(3);

    std::cout << "Vector Size: " << numVector.size() << std::endl;

    std::cout << "------------------------------------------------------------" << std::endl;

    //While Loops
    //Looping continue until the condition at the top becomes false
    int i = 1;
    while (i <= 20) {
        if (i % 2 == 0) {
            i++;
            //Continue to the new loop
            continue;
        }

        //break: Exit the while loop completely
        if (i == 15)
            break;

        std::cout << i << std::endl;
        i++;
    }

    std::cout << "------------------------------------------------------------" << std::endl;

    //Using while loop with a String Stream
    std::vector<std::string> words;

    std::stringstream stringStream("Random Words PADORU PADORU");
    std::string word;
    while (std::getline(stringStream, word, ' ')) {
        words.push_back(word);
    }

    //index-based for loop to iterate over an array
    for (int j = 0; j < words.size(); ++j) {
        std::cout << words[j] << std::endl;
    }

    std::cout << "------------------------------------------------------------" << std::endl;

    //It's bad practice to use range-based for loops over CArrays (AFFECTS PERFORMANCE)
    int arr3[] = {1, 2, 3};

    std::array<int, 3> arr4{1, 2, 3};
    //range-based for loop to iterate over an array
    for (auto x: arr4) {
        std::cout << x << std::endl;
    }

    std::cout << "------------------------------------------------------------" << std::endl;

    //Do While Loop
    //Random number guessing game
    //Generate a random number with a time seed
    srand(time(NULL));
    int secretNum = rand() % 11;
    int guess = 0;

    do {
        std::cout << "Guess the Number: ";
        std::cin >> guess;
        if (guess > secretNum)
            std::cout << "Too Big\n";
        if (guess < secretNum)
            std::cout << "Too Small\n";
    }while (secretNum != guess);

    std::cout << "You guessed it!" << std::endl;

    std::cout << "------------------------------------------------------------" << std::endl;

    //Strings
    //a series of chars
    std::string string1 = "I'm Example String";
    //First Char of the string
    std::cout << "1st: " << string1[0] << std::endl;
    //Last Char of the string
    std::cout << "1st: " << string1.back() << std::endl;
    //Length of the string
    std::cout << "1st: " << string1.length() << std::endl;
    //copy a whole string
    std::string string2 = string1;
    //copy a part of a string
    std::string string3(string2, 4);
    //combine strings
    std::string string4 = string1 + " and you're not";
    string4.append("!");
    std::cout << string4 << std::endl;
    string4.erase(12, string4.length() - 1);
    std::cout << "New String: " << string4 << std::endl;

    //Find the index where the first occurrence of the searched string is found
    //std::string::npos is the standard
    if (string1.find("string") != std::string::npos)
        std::cout << "string Index: " << string1.find("string") << std::endl;

    //Trims a string into a substring depending on the given parameters
    std::cout << "Substring: " << string4.substr(6, 6) << std::endl;
    //Converting a number to a string
    std::string stringNum = std::to_string(1+3);

    std::cout << "------------------------------------------------------------" << std::endl;

    //Char Functions
    char letterj = 'j';
    char char5 = '5';
    char space =  ' ';

    std::cout << "Is 'j' a letter or a number: " << std::isalnum(letterj) << std::endl;
    std::cout << "Is 'j' a letter: " << std::isalpha(letterj) << std::endl;
    std::cout << "Is '5' a number: " << std::isdigit(char5) << std::endl;
    std::cout << "Is ' ' a space: " << std::isspace(space) << std::endl;

    std::cout << "------------------------------------------------------------" << std::endl;

    //Math Functions
    std::cout << "abs(-10) = " << std::abs(-10) << std::endl;
    std::cout << "max(5, 3) = " << std::max(5, 3) << std::endl;
    std::cout << "min(5, 3) = " << std::min(5, 3) << std::endl;
    std::cout << "fmax(5, 3) = " << std::fmax(5.3, 5.8) << std::endl;
    std::cout << "fmin(5, 3) = " << std::fmin(5.3, 5.8) << std::endl;
    std::cout << "ceil(10.30) = " << std::ceil(10.30) << std::endl;
    std::cout << "floor(10.30) = " << std::floor(10.30) << std::endl;
    std::cout << "round(10.30) = " << std::round(10.30) << std::endl;
    //x^y
    std::cout << "pow(2, 3) = " << std::pow(2, 3) << std::endl;
    //square root
    std::cout << "sqrt(25) = " << std::sqrt(25) << std::endl;
    //cube root
    std::cout << "cbrt(1000) = " << std::cbrt(1000) << std::endl;
    //e^x
    std::cout << "exp(1) = " << std::exp(1) << std::endl;
    //2^x
    std::cout << "exp2(1) = " << std::exp2(1) << std::endl;
    //logarithm
    std::cout << "log(1) = " << std::log(1) << std::endl;
    //hypothenuse (SQRT(X^2 + Y^2))
    std::cout << "hypot(2, 3) = " << std::hypot(2, 3) << std::endl;

    //other functions
    //sin, cos, tan, asin, acos, atan, sinh, cosh, tanh, asinh, acosh, atanh

    std::cout << "------------------------------------------------------------" << std::endl;

    //Custom Functions: Function Prototype (Makes sure you can call AddNumbers even if it's defined later in the file)
    double AddNumbers(double num1, double num2);
    void AssignAge(int age);

    std::printf("%.1f + %.1f = %.1f\n", 5.3, 7.3, AddNumbers(5.3, 7.3));

    //Variables in method are passed by reference, the function is a completely detatched block of code
    int agetest = 9;
    AssignAge(agetest);
    std::cout << agetest << std::endl;

    std::cout << "------------------------------------------------------------" << std::endl;
    //POINTERS: Stores an address in memory
    void assignAge2(int* pAge);

    int age2 = 43;
    assignAge2(&age2);
    std::cout << age2 << std::endl;

    //declaring a pointer
    int* pAge = nullptr;
    //& is a REFERENCE OPERATOR returns the address for a variable
    pAge = &age;
    //Printing the memory address of the pointer
    std::cout << "Address: " << pAge << std::endl;
    //Printing the value the memory address points to
    //* returns the value from a memory address (the exact opposite of &)
    std::cout << "Value: " << *pAge << std::endl;

    //Pointer to an Array
    void DoubleArray(int *arr, int size);

    int intArr[] = {1, 2, 3, 4};
    int* pIntArray = intArr;
    std::cout << "1st address: " << pIntArray << std::endl;
    pIntArray++;
    std::cout << "2nd address: " << pIntArray << std::endl;

    DoubleArray(pIntArray, 4);
    for (int k = 0; k < 4; ++k) {
        std::cout << "Value " << k+1 << ": " << intArr[k] << std::endl;
    }

    std::cout << "------------------------------------------------------------" << std::endl;
    //Exception Handling
    int dividend = 10, divisor = 0;
    try {
        if (divisor == 0) {
            //Throws an exception
            throw "Division by Zero Exception";
        } else {
            printf("%.1f / %.1f = %.1f", dividend, divisor, dividend / divisor);
        }
    } catch (const char* e) {
        std::cout << "Error: " << e << std::endl;
    }

    std::cout << "------------------------------------------------------------" << std::endl;
    //Objects and Classes - Fields, Methods
    void printArea(Shape& shape);
    Rectangle square(5);
    Circle circle(10);
    printArea(square);
    printArea(circle);

    std::cout << "------------------------------------------------------------" << std::endl;

    //Structs
    ShapeStruct shape(10, 6);
    std::cout << "Square Area: " << shape.area() << std::endl;
    CircleStruct circleStruct(10);
    std::cout << "Square Area: " << circleStruct.area() << std::endl;

    std::cout << "------------------------------------------------------------" << std::endl;

    //Operator overloading on a Box object
    Box box(10, 10, 10);
    ++box;
    std::cout << box.operator const char *() << std::endl;
    Box box2(5, 5, 5);
    std::cout << "Box1 + Box2 = " << (box + box2).operator const char *() << std::endl;
    std::cout << "Box1 == Box2 = " << (box == box2) << std::endl;

    std::cout << "------------------------------------------------------------" << std::endl;



    //When There's no errors the main function should return 0
    //The main function returns 0 implicitly if you don't return anything
    return 0;
}
