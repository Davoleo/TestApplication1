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
#include <array>        // C++ arrays
#include <string>       // Strings
#include <fstream>      // File I/O and String streams
#include <numeric>      // Work with Sequences of values
#include <ctime>        // Work with time
#include <cmath>        // Common Math Functions
#include <sstream>      // String Streams

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


    //When There's no errors the main function should return 0
    return 0;
}