//
// Created by Davoleo on 28/09/2019.
//

// This is single-line a comment
/*
 * Multi-line Comment
 */

//What begins with a # is a preprocess statement (they are read before actual code compilation)
//Include takes everything that is inside of the linked header files and puts them into the main file (literally copy and paste lul)
//header files that don't have an extension usually are C++ header files while the ones with .h extension are usually C header files
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
#include <memory>       // Smart Pointers
#include <cstring>

//Creates an alias for something
#define INTEGER int

#include "models/shapes/Shape.h"
#include "models/Box.h"
#include "models/shapes/Rectangle.h"
#include "models/shapes/Circle.h"
#include "models/shapes/shapestructs.h"
#include "Logger.h"
#include "models/String.h"

//Available in all functions
INTEGER globalVar = 0;

class Player {

private:
    int x, y;
    int speed;
    std::string name;
    mutable bool muuuutable;

public:
    //Constructors
    //Handle private members initialization and is called whenever you create a new instance of a class
    Player() {
        x = 0;
        y = 0;
        speed = 0;
        std::cout << "Player has been created!" << std::endl;
    }

    Player(int x, int y, int speed) {
        this->x = x;
        this->y = y;
        this->speed = speed;
        std::cout << "Player has been created!" << std::endl;
    }

    //Destructor
    //Is called at the end of a scope where the object instance should be deleted and used memory should be cleaned
    ~Player() {
        std::cout << "Player Was DESTROYED!" << std::endl;
    }

    void move(int xa, int ya) {
        x += xa * speed;
        y += ya * speed;
    }

    //CONST at the end of a method signature means that it's promising to only read values from the class and it's not going to make any change
    int getX() const {
        //Although this method can still change mutable variables
        muuuutable = true;
        return x;
    }

    const std::string& getName() const {
        muuuutable = false;
        return name;
    }

    //static variables inside of classes and structs do not belong to the actual object (they're not members of the class)
    //you can usually refer to them as if they were defined in a namespace that has the same name as the class (Player::count)
    static int count;

    static void incrementCount() {
        count++;
    }

    void print() const {
        std::cout << "Player's Name: " << name << "\nPlayer's Position: " << x << ", " << y << "\nPlayer's Speed: " << speed << std::endl;
    }
};

class ScopedPointer {
private:
    Box* boxPtr;
public:
    ScopedPointer(Box* pointer) : boxPtr(pointer)
    {
    }

    ~ScopedPointer()
    {
        delete boxPtr;
    }

    //You can override the arrow operator to return a different thing so that you can use it directly on the Box pointer for example
    Box* operator->() {
        return boxPtr;
    }

    //A version for const pointers
    const Box* operator->() const {
        return boxPtr;
    }
};

//function declaration (only the signature)
//This declaration is wired up to the real definition by the linker
int Multiply(int a, int b);
void Increment(int* value);
void Increment(int& value);
void sFunction();

//Define the static variable (avoid linker errors)
int Player::count;

//Overriding the << operator in std
//It's sorta like overriding toString() in Java
std::ostream& operator << (std::ostream& stream, const Box& box)
{
    stream << "Box Name: " << box.getBoxName() << "\tBox Size: (" << box.getWidth() << ", " << box.getHeight() << ", " << box.getDepth() << ")";
    return stream;
}

std::ostream& operator << (std::ostream& stream, const String& string)
{
    //Can Access buffer private variable because this operator is a friend of the class
    stream << string.buffer;
    return stream;
}

//First function executed at runtime line-by-line
//Every cpp file is compiled to a .obj file (by the compiler)
//All the .obj files are archived together into an .exe file by the linker
int main(int argc, char** argv) {

    Logger logger;

    //#if preprocess statements include or exclude some code whether the condition is true or false
#if 1
    std::cout << "Conditioned code" << std::endl;
#endif

    //Basic Hello World
    //Cout prints the text on the screen / std::endl puts a carriage return at the end
    // the "<<" operator puts the "Hello World" String in the output stream
    // << is an overloaded operator (just like a function that is called on cout)
    std::cout << "Hello World" << std::endl;

    //primitive Data types variables
    //Stored in memory

    //booleans (can either be true or false) (takes 1 bit of data although packed inside a byte [the only way to access the value])
    bool sampleBool = true;
    //integers
    int age;
    std::cout << "ENTER YOUR FUCKING AGE! ";
    //Captures user input
    std::cin >> age;
    // Other ints
    // unsigned versions (can reach double the range of the signed version but cannot store negative numbers (MIN = 0))
    unsigned int positiveNum = 123;
    //any numeric data type can also store chars
    //char (1 byte of data) | Contains just one character | 1 byte | enclosed in single quotes
    char epicChar = 'K';
    //short (2 bytes of data)
    //int (4 bytes of data) (range: -2b -> 2b) (signed)
    //long (usually 4 bytes of data)
    //long long (usually 8 bytes of data)

    // Constant double value (can contain decimal points) | Accurate up to 15 digits | takes 8 bytes of data
    const double PI = 3.1415926535;
    //floats: accurate up to 6 decimal points | they take up less memory | takes 4 bytes of data
    float overFloat = 3.3333333F;
    float overFloat2 = 3.3333333F;
    //Loss Of precision
    std::printf("OverFloat Sum = %.7F\n", (overFloat + overFloat2));

    //Define Pointers and References
    //bool*
    //bool&

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

    //Implicit conversion from string to Box because there's a constructor that takes one size
    //Implicit conversion can only happen once contemporarily
    Box sizeBox = 22;

    logger.info("Test");
    std::cout << Multiply(5, 8) << std::endl;

    std::cout << "----------------------- Casting ---------------------------" << std::endl;

    std::cout << "4 / 5 = " << 4 / 5 << std::endl;
    std::cout << "4 / 5 = " << (float) 4 / 5 << std::endl;

    std::cout << "------------------------ If Statement----------------------" << std::endl;

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

    //Ternary Operator (Conditional Assignment)
    //variable = condition ? ifTrue : ifFalse
    int speed = age >= 10 ? 5 : 20;
    std::cout << "what's your speed? " << speed << std::endl;

    std::cout << "------------------------- LOOPS ------------------------------" << std::endl;

    //LOOPS
    //while loops often used when you already have a condition and there's no need to change any variable to make it work
    //for loops often used when you know how many times you're going to iterate a piece of code (iterating over arrays)

    //CONTROL FLOW STATEMENTS
    //continue, break and return are control flow statements

    //While Loops
    //Looping continue until the condition at the top becomes false
    int i = 1;
    while (i <= 20) {
        if (i % 2 == 0) {
            i++;
            //Continue to a new iteration of the loop (condition is still checked and iterator value is still increased)
            continue;
        }

        //break: Exit the while loop completely
        if (i == 15)
            break;

        std::cout << i << std::endl;
        i++;
    }

    std::cout << "------------------------- CArrays ------------------------------" << std::endl;

    //It's bad practice to use range-based for loops over CArrays (AFFECTS PERFORMANCE)
    int arr3[] = {1, 2, 3};
    //CArrays are of a fixed size - you can't change how much space is allocated

    std::array<int, 3> arr4{1, 2, 3};
    //range-based for loop to iterate over an array
    for (auto x: arr4) {
        std::cout << x << std::endl;
    }

    std::cout << "---------------------- Do While Loop -----------------------" << std::endl;

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

    std::cout << "------------------------ POINTERS --------------------------" << std::endl;

    //POINTERS: A variable that Stores a memory address [a number] (types are meaningless, cause in memory everything is stored as a number)
    //Giving a data type to a pointer is just presuming what data type is stored at that address
    //0 is an invalid value for a memory address (hence you can't read or write to that address [program will crash])
    //An alias for a pointer to 0 is NULL (#define NULL 0) or nullptr (from C++ 11)
    void* purePointer = nullptr;

    int ageVar = 8;
    //Take the address of the variable 8 in memory and store it in the agePtr Pointer - & is a REFERENCE OPERATOR
    int* agePtr = &ageVar;
    //Printing the memory address of the pointer
    std::cout << "Address: " << agePtr << std::endl;
    //dereferencing the address -> take the actual variable from the pointer
    //* returns the value from a memory address (the exact opposite of &)
    *agePtr = 10;
    //Printing the value the memory address points to
    std::cout << "Value: " << ageVar << std::endl;

    //Allocates 8 bytes of data (1 byte for every char) and then returns the address to it as a pointer
    char* buffer = new char[8];
    //Fills a certain memory address with the second parameters value for a size specified in the third parameter
    memset(buffer, 0, 8);

    //storing a pointer in memory means that, that pointer might have an address (that's when you get to double and triple pointers)
    //double pointer
    char** pointerToBuffer = &buffer;

    //When working with memory this way you should also delete the used memory
    delete [] buffer;

    void assignAge2(int* pAge);

    int age2 = 43;
    assignAge2(&age2);
    std::cout << age2 << std::endl;

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

    std::cout << "------------------------ REFERENCES ------------------------" << std::endl;

    //REFERENCES
    // (They're just pointers in disguise)
    //A way to reference a real existing variable (a memory address without all the crap that pointers bring)
    int a = 5;
    //Alias for the a variable
    int& ref = a;
    ref = 2;
    log(a); //Will be 2

    //Passing parameters as pointers or references
    //it's an easy way of passing the address of a variable instead of taking a pointer parameter and then dereferencing it
    //you can pass directly the a variable without taking its address
    Increment(&a);
    Increment(a);

    //you can't change a reference to something this code would just set 'a' equals to 'secretNum'
    //ref = secretNum;

    std::cout << "------------------------- SMART POINTERS -------------------" << std::endl;

    //SMART POINTERS
    //Automate the process of freeing used memory "delete"

    //Unique pointers are scoped pointers to memory blocks that are freed whenever the pointer goes out of scope
    //They're called unique because you can't copy them, if you copied them you would have to pointers to the same block of memory and once one of them frees
    //the memory they're pointing to when they're destroyed then the other one still points to some memory that was already freed
    std::cout << "--- Entering Unique Pointers Scope ---" << std::endl;
    {
        std::unique_ptr<Player> player = std::make_unique<Player>();
        player->print();
        //This is not goint to work because the copy constructor is deleted in the unique_pointer class to avoid the problems described above
        //std::unique_ptr<Player> p0 = player;
    }
    //The player unique pointer will be destroyed here

    //Shared pointers are not unique and there can be multiple ones that can point to a block of memory
    //How they work is that they keep a count of pointer references that are active and the memory block will be freed only when this count reaches 0
    std::cout << "--- Entering Shared Pointers Scope ---" << std::endl;
    {
        std::shared_ptr<Player> p0;
        {
            std::shared_ptr<Player> sharedPlayer = std::make_shared<Player>();
            p0 = sharedPlayer;

            //Weak Pointers can be assigned to shared pointers but they do not increase the reference count of the shared pointer
            //Meaning that they don't stop the block of memory they're pointing to from being freed, however you can ask them if the pointer is still valid
            std::weak_ptr<Player> weakPlayer = p0;
        }
    }

    std::cout << "------------- Copying and Copy Consctructors ---------" << std::endl;

    //Copying and copy Constructors
    String myString = "Custom String class pog";
    //This performs a copy - although it also copies a pointer that points to the same memory block as the other string buffer
    //Called Shallow Copy (when it's not specified otherwise in the class through a copy constructor)
    String myString2 = myString;
    std::cout << myString << std::endl;

    std::cout << "-----------------------Char Functions ----------------------" << std::endl;

    //Char Functions
    char letterj = 'j';
    char char5 = '5';
    char space =  ' ';

    std::cout << "Is 'j' a letter or a number: " << std::isalnum(letterj) << std::endl;
    std::cout << "Is 'j' a letter: " << std::isalpha(letterj) << std::endl;
    std::cout << "Is '5' a number: " << std::isdigit(char5) << std::endl;
    std::cout << "Is ' ' a space: " << std::isspace(space) << std::endl;

    std::cout << "------------------- Math Functions --------------------------" << std::endl;

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

    //other math functions
    //sin, cos, tan, asin, acos, atan, sinh, cosh, tanh, asinh, acosh, atanh

    std::cout << "--------------------- Functions -----------------------" << std::endl;

    //Functions: Are not part of a class
    //Methods: Are part of a class
    //Functions: Function Prototype (Makes sure you can call AddNumbers even if it's defined later in the file or in another file)
    double AddNumbers(double num1, double num2);
    void AssignAge(int age);

    std::printf("%.1f + %.1f = %.1f\n", 5.3, 7.3, AddNumbers(5.3, 7.3));

    //Variables in method are passed by reference, the function is a completely detatched block of code
    int agetest = 9;
    AssignAge(agetest);
    std::cout << agetest << std::endl;

    std::cout << "------------------- std::vectors (Dynamic Arrays) -------------------" << std::endl;

    //Vectors
    //Dynamic Arrays (used when you don't know how many items you're going to store)
    //You can also use primitive types as parameters
    std::vector<int> numVector(2);
    numVector[0] = 1;
    numVector[1] = 2;
    //Adds an item to the end of the vector
    numVector.push_back(3);

    std::cout << "Vector Size: " << numVector.size() << std::endl;

    //Storing objects themselves in general "should" be more optimized (they're all in line in memory (optimal to read and loop over them))
    //While if you have an array you need to modify many times it should be more optimal to store pointers
    std::vector<Box> boxes; // = std::vector<Box>(3); this will already construct 3 vertex objects
    //This usually does 6 Box copies to add all three boxes
    //(consctructs the Box here and then copies it to the right memory location)
    //boxes.push_back(Box(1));
    //boxes.push_back(Box(2));
    //boxes.push_back(Box(3));

    boxes.reserve(3); //reserve reserves memory space for a number of objects (so that you don't need to expand the vector to add each item)
    //emplace_back instead of push_back consctructs the object directly where it needs to be stored and we only need to pass the parameters
    boxes.emplace_back(1);
    boxes.emplace_back(2);
    boxes.emplace_back(3);

    //Range-based loop over dynamic arrays
    for (Box& boxe : boxes)
        std::cout << boxe;

    //Delete an element starting from an iterator position (?) [beginning of the array + 1]
    boxes.erase(boxes.begin() + 1);
    //Clears the vector
    boxes.clear();

    std::cout << "-------------------- Exception Handling ---------------------" << std::endl;
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

    std::cout << "------------------- Raw Arrays (CArrays) ----------------------" << std::endl;

    //Raw Arrays: A collection of multiple variables (usually of the same type) under one single name

    //there is no way to find out the length of a raw array except using sizeof() [which is dangerous because it's compiler dependant]
    //so you need to keep track of the length of the array yourself (using things like constants)
    static const int myColorsLength = 5;

    //Create an array of five slots
    int myColors[myColorsLength];
    //First Element
    myColors[0] = 0x6C6C6C;
    //Last Element
    myColors[4] = 0xEC1258;

    //This causes a MemoryAccessViolation Error in Debug mode (because we're trying to edit at a memory address which isn't part of the array)
    //However in production mode this doesn't throw any error, which may lead to some serious bugs
    //myColors[-1] = 2;
    //myColors[5] = 2;

    //Arrays can be considered pointers to memory address that contain multiple values
    int* myColorsPtr = myColors;
    //Array logic can be rewritten using pointers
    myColors[2] = 5;
    //Increment the pointer by 2 (adds 2 times the size of the integer) and then assign it to five
    *(myColorsPtr + 2) = 5;

    //Since it was created in the heap it will remain alive even out of this scope until the program ends or it's manually deleted by the code
    //you usually do this when you're:
    //- returning something from a function (and it's not a pointer)
    //if you don't need to create things in the heap then you should avoid it since it's stored in another memory address and causes jumping between different addresses (affects performance I guess)
    int* heapArray = new int[5];
    delete[] heapArray;

    //Looping over an array to set values
    for (int j = 0; j < 5; ++j) {
        std::cout << "Element " << j << ": " << myColors[j] << std::endl;
        myColors[j] = 2;
    }

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

    //Using C++11 standard arrays
    std::array<int, 5> standardArray{};

    for (int& j : standardArray) {
        j = 333;
    }

    std::cout << "----------------- CStrings and std::strings -----------------" << std::endl;

    //Strings (an array of characters)

    //CStyle String
    //Most people just make these constant because strings are, by nature, immutable
    // (using it as a variable might cause undefined behaviour [not reliable])
    //if you really want to edit a string you need to manipulate it as an array instead of a pointer
    //String literals are always store in readonly memory

    //String are represented in memory as a series of ASCII byte codes with a null termination char ("00")
    const char* cString = "Davoleo";
    //Prints until it finds the null termination char
    std::cout << cString << std::endl;
    //Length of a CString
    strlen(cString);

    //Create a CString manually as an array (this is not a string and doesn't have a terminator char)
    //hence when we print this all the rest of the memory address is going to be printed as well
    char charArray[7] = { 'D', 'a', 'v', 'o', 'l', 'e', 'o'};
    std::cout << charArray << std::endl;

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
    string1 += " and you're not";
    string1.append("!");
    std::cout << string1 << std::endl;
    string1.erase(12, string1.length() - 1);
    std::cout << "New String: " << string1 << std::endl;

    //Find the index where the first occurrence of the searched string is found
    // [std::string::npos is an illegal position that is returned if the string is not found (sorta like -1 in indexOf in js)]
    if (string1.find("string") != std::string::npos)
        std::cout << "string Index: " << string1.find("string") << std::endl;

    //Trims a string into a substring depending on the given parameters
    std::cout << "Substring: " << string1.substr(6, 6) << std::endl;
    //Converting a number to a string
    std::string stringNum = std::to_string(1+3);

    //String literals (in the most basic example they become const char arrays)
    //The size of these arrays are one than the string actual length because of the null terminator char at the end
    const char* name = "Davo\0leo"; //Manually inserting a null terminator breaks some functions like strlen
    std::cout << "Davoleo Broken Length: " << strlen(name) << std::endl;

    //to enforce a normal const char literal you use 'u8' in front of the string

    //Define a string literal made of wide characters
    //can be 2 or 4 bytes long character (usually 2 on Windows and 4 on Unix)
    const wchar_t* widePutinString = L"Wide Melonpan is here to steal your waifus";
    //2 bytes long character
    const char16_t* char16String = u"";
    //4 bytes long characters
    const char32_t* char32String = U"";

    //Since C++14 you can write std string literals
    //The s operator at the end convers the CString to an std::string
    using namespace std::string_literals;
    std::string literallyString = "dsakdjdasd"s;
    std::wstring wliteralString = L"djaskdjasdk"s;

    //R stands for RAW (botch)
    const char* ignoreEscapes = R"(Multiline string
that
ignores
escapeeeee
characters)";

    std::cout << "------------------------- CONST ------------------------------" << std::endl;

    //CONSTANTS

    int variableInt = 5;
    variableInt = 2; // Can be changed

    const int constantInt = 5;
    //constantInt = 2; Cannot be changed

    //If const is put after the type specification it works the opposite way (content is variable but address is constant)
    //You can also put 2 const to make both the content and the address constant
    const int* constantPointer = new int;
    //*constantPointer = 2; since the pointer is declared as const you can't change its CONTENTS
    //This breaks the constant promise of constantInt and could resolve in crashes
    constantPointer = (int*)&constantInt; // but you can change the address at which the pointer points

    Player constGetter;
    //This is a const method, it's not going to change the private member X in any way
    constGetter.getX();

    int x = 9;
    //Allows to edit variable passed by value in lambdas if the lambda is declared as mutable
    auto lamda = [=]() mutable {
        x++;
        std::cout << x << std::endl;
    };

    std::cout << "------------- OOP Objects Classes Fields and methods ----------" << std::endl;

    //Objects, Classes, Fields and Methods
    //Variables made of class types are called objects (instances of a class)
    //members are private by default
    //complex abstraction of objects
    void printArea(Shape& shape);
    Rectangle square(5);
    Circle circle(10);
    printArea(square);
    printArea(circle);

    Player player;
    //private member
    //player.x = 5;
    player.move(5, 2);

    logger.setLevel(Logger::Level::WARNING);
    logger.info("Hello info");
    logger.warn("HELLO Worldo!");
    logger.warn("Hello Erroru!");

    //Initialization

    //On the STACK or the HEAP
    //Stack variables have an automatic lifespan that ends whenever the execution goes out of scope (the stack pops and all the memory is freed)
    //The Stack is like java's Stack data structure, a pile of stuff in which you can only interact with the first element of it and to interact with the element below you have to pop the first element
    Box stackBox = Box(1, 2, 3, "Boxx");
    stackBox.getBoxName();

    //Heap variables remain there !!until you explicitly free the memory!!
    //You may have to allocate on the heap when either you want the variable to persist across scopes and when you have
    //to allocate a big quantity of memory that wouldn't fit in the stack (usually 1/2MB)
    //Allocating on the heap takes longer than allocating on the stack (because it needs to find a pointer to a location in the memory that has enough space)
    //In Java EVERYTHING is allocated on the heap - in C# all classes are allocated on the heap (structs are allocated on the stack instead)
    Box* boxPointer;
    {
        //The location on the heap is returned (not the actual object)
        //Allocates memory on the heap (using C function 'malloc()') AND calles the constructor
        Box* secondBox = new Box("BoiBox");
        boxPointer = secondBox;
        std::cout << secondBox->getBoxName() << std::endl;

        int* heapArray = new int[5];
        delete [] heapArray;

        //Allocating on the heap although automating the destruction of the object once the execution goes out of scope
        ScopedPointer heapBox = new Box("AutomatedHeapBox");
        //The ScopedPointer class wraps the pointer so that when the destructor on the wrapper is called it destroys the heap allocated Box
    }

    //deleting secondBox allocated on the heap after the scope is closed
    //frees memory on the heap (using C function 'free()') AND calles the destructor
    delete boxPointer;

    std::cout << "-----------------  The Arrow Operator  ---------------------" << std::endl;

    //Works just fine with objects
    Box boxObj;
    boxObj.getBoxName();

    Box* boxPtr = &boxObj;
    //boxPtr.getBoxName(); Wont't work
    (*boxPtr).getDepth(); //You can do it by dereference it although there's a shortcut which is ...

    //The arrow operator ->
    std::cout << "Box Pointer Depth: " << boxPtr->getDepth() << std::endl;

    //Overriding the -> operator
    ScopedPointer scopedPtr = new Box();
    std::cout << "Scoped Box Pointer Width: " << scopedPtr->getWidth() << std::endl;

    //get The offset in memory of a specific field in a struct
    //Casting the null pointer to a Box pointer and getting the depth field trhough the arrow operator and then take the address of it and cast it to an int
    //int depthFieldOffset = (int) &((Box*)nullptr)->depth;
    //this operation is more easily done by using the offsetof macro
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
    std::cout << "height field offset in ShapeStruct: " << offsetof(ShapeStruct, height) << std::endl;
#pragma clang diagnostic pop


    std::cout << "-------------------------- STATIC --------------------------" << std::endl;
    //The meaning of static:
    // - outside of a class -
    //variable/method only linked internally in this translation unit
    // in case another int variable with the same name is defined elsewhere the linker will not error
    //As if it was declared private
    static int staticVar = 5;

    //The meaning of extern:
    //The linker looks for a variable with the same name inside of an external translation unit and reference that variable
    extern int functionsID;

    //static variable inside a class
    Player::count = 25;
    Player::incrementCount();

    //static in a local scope
    //lifetime: how long the variable remains in memory
    //scope
    //of a variable
    //Makes the variable initialized one time only even when the function is called multiple times
    sFunction();
    sFunction();
    sFunction();
    sFunction();
    sFunction();

    std::cout << "----------------------- Structs ----------------------" << std::endl;

    //Structs
    //members are Public by default
    //Usually used when there's not much functionality to it
    ShapeStruct shape(10, 6);
    std::cout << "Square Area: " << shape.area() << std::endl;
    CircleStruct circleStruct(10);
    std::cout << "Square Area: " << circleStruct.area() << std::endl;

    std::cout << "---------------------- Enums -----------------------" << std::endl;

    //Enums
    // the : is used to specify what data type the enum actually is (it has to be a non floating-point number)
    enum Example : unsigned char{
        Alpha,
        Beta,
        Gamma,
        Delta,
        Epsilon
    };

    Example value = Gamma;

    std::cout << "---------------- Operator Overloading -----------------" << std::endl;

    //Operator overloading (define or change the behaviour of an operator)
    //Operators: Symbols that allow developers to apply something they usually replace functions

    Box box(10, 10, 10, "10Box");
    ++stackBox;
    std::cout << stackBox << std::endl;
    Box box2(5, 5, 5, "5Box");
    std::cout << "Box1 + Box2 = " << (stackBox + box2) << std::endl;
    std::cout << "Box1 == Box2 = " << (stackBox == box2) << std::endl;

    //When There's no errors the main function should return 0
    //The main function returns 0 implicitly if you don't return anything
    return 0;
}
