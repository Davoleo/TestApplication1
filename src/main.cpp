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
#include <vector>       // Vectors (dynamic arrays)
#include <tuple>        // Tuples (structs to hold multiple different data types)
#include <optional>     // Optional data  (safe way of saying that data could be there or could not)
#include <variant>      // Variant data (variable that can contain and handles a variable of one or other data types)
#include <any>          // The Any variable type (store any kind of data in the same variable)
#include <array>        // C++ static arrays
#include <string>       // Strings
#include <fstream>      // File I/O and String streams
#include <numeric>      // Work with Sequences of values
#include <ctime>        // Work with time
#include <cmath>        // Common Math Functions
#include <sstream>      // String Streams
#include <memory>       // Smart Pointers
#include <cstring>      // Contains Functions (coming from C's string.h) to manipulate CStrings
#include <functional>   // Contains a class to work smoothly with Function pointers and lambdas
#include <algorithm>    // Contains STL Functions for all kinds of collections and common operations
#include <thread>       // Multithreading support (raw threads)
#include <future>       // std::async and futures support  (asynchrounous tasks)
#include <chrono>       // Timing functions support
#include <unordered_map>// Hash Maps basically

#include <cstddef>      // Contains the offsetof() macro

//Creates an alias for something
#define INTEGER int

//Own project headers
#include "models/shapes/Shape.h"
#include "models/Box.h"
#include "models/shapes/Rectangle.h"
#include "models/shapes/Circle.h"
#include "models/shapes/shapestructs.h"
#include "Logger.h"
#include "models/String.h"
#include "timer.h"

//Available in all functions
INTEGER globalVar = 0;

//Pre-Processor Macros replace text in the source code with something else
//templates are evaluated later during the actual compilation
#define WAIT std::cin.get()

//If NOT debug is NOT defined (which means the process is ran in debug mode then the logging code will be present)
#ifndef NDEBUG
#define PRINT(X) std::cout << X << std::endl
#else
#define PRINT(X)
#endif

//Multi-line Macro example
#define EXPLODE void explode() {\
    PRINT("You're about to initiate self-destruct sequence"); \
}

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

template <typename T, int N>
class StackArray
{
private:
    T array[N];
public:
    int getSize() const {
        return N;
    }
};

//function declaration (only the signature)
//This declaration is wired up to the real definition by the linker
int Multiply(int a, int b);
void Increment(int* value);
void Increment(int& value);
void sFunction();
void hello_spam();
void printString(const std::string& string);
void printCustomStringRValue(String&& string);

template<typename T>
void templatePrint(T value) {
    std::cout << value << std::endl;
}

//Used In "function pointers"
void hello_world(int);
typedef void(*IntConsumer)(int);
void for_each(const std::vector<int>&, IntConsumer);

//Define the static variable (avoid linker errors)
int Player::count;

static bool s_finished = false;

//Overriding the << operator in std
//It's sorta like overriding toString() in Java
std::ostream& operator << (std::ostream& stream, const Box& box)
{
    stream << "Box Name: " << box.getBoxName() << "\tBox Size: (" << box.getWidth() << ", " << box.getHeight() << ", " << box.getDepth() << ')' << std::endl;
    return stream;
}

std::ostream& operator << (std::ostream& stream, const String& string)
{
    //Can Access buffer private variable because this operator is a friend of the class
    stream << string.buffer;
    return stream;
}

///NAMESPACES
///They exist to avoid name conflicts (for functions, variables, classes and everything)
///To call this function from out of this namespace you need to use the scope access operator '::'
///@code e.g.: test::print("helo")
namespace test {
    void print(const std::string& string) {
        std::cout << string << std::endl;
    }
}

//First function executed at runtime line-by-line
//Every cpp file is compiled to a .obj file (by the compiler)
//All the .obj files are archived together into an .exe file by the linker
int main(int argc, char** argv) {

    int sectionId;

    std::cout << "Input the section you want to run:" << std::endl;
    std::cout << "1: main" << std::endl;
    std::cout << "2: legacy_main" << std::endl;
    std::cout << "3: worldo_test" << std::endl;
    std::cout << "4: Memory_Allocation" << std::endl;
    std::cin >> sectionId;

    int section_world_test();
    int section_legacy_code();
    int section_memory_tracking();

    switch (sectionId)
    {
    case 2:
        return section_legacy_code();
    case 3:
        return section_world_test();
    case 4:
        return section_memory_tracking();
    default:
        break;
    }

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
    //
    //RVALUES & LVALUES
    //An LValue is a value that you can assign to another RValue or LValue (e.g. sampleBool)
    //An RValue is a value that can't be assigned to another value for example the constant true, and it's a temporary value that is not stored in memory
    //You can't assign anything to an RValue (example you can't assign anything to the constant 'true')
    //
    //If you have a function that returns an integer 10 and you try to assign the call of the function to something else you will get a compiler
    //error saying that you can't assign something to an RValue because by default functions return values in temporary storage that can't be modified
    //While if the function returns an int reference (&) you will be able to assign the call of the function to another value effectively changing
    //The value stored inside of the function (LValue reference)
    // 
    //Another example is that you can't pass an RValue to a function that accept a reference as a parameter
    //
    //Also when you assign complex expressions to a variable the expressions are considered RValues since they're not stored anywhere and they're temporary
    //
    //There are 3 ways of deciding whether you want to accept LValues only RValues only or both in C++
    //- you can assign both RValues and LValues to const references (const type&)
    //- you can only assign LValues to simple references (type&)
    //- you can only assign RValues to double references (type&&)
    //
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
    //this variable is automatically inferred to an int (as numeric literals are ints by default)
    //- It can be useful as if the right part of the expression changes you can keep the left part of the assignment the same and it would work anyways
    //- Although it could lead to break some stuff
    //- It's also less clear what's the actual type of the variable.
    auto inferredVar = 1231;
    std::string emptyString = "123";

    std::vector<std::string> fruits;
    fruits.emplace_back("apple");
    fruits.emplace_back("orange");

    //ITERATORS
    //Iterating with an iterator
    //instead of writing std::vector<std::string>::iterator which is a really long type you can use auto
    for (auto iterator = fruits.begin(); iterator != fruits.end(); iterator++) {
        //It works through dereference because * is overridden in the iterator class
        std::cout << *iterator << std::endl;
    }

    //Range-Based for loop (work if iterators are provided by the class [shorthand syntax for the previous loop])
    for (std::string fruit : fruits)
        std::cout << fruit << std::endl;

    //Iterators with Hash Maps
    using score_map = std::unordered_map<std::string, int>;
    score_map scoreHashMap;
    scoreHashMap["Dav"] = 3;
    scoreHashMap["Zambo"] = 6;
    scoreHashMap["Nexn"] = 5;

    //It can also be done with range-based for loops
    for (score_map::const_iterator it = scoreHashMap.begin(); it != scoreHashMap.end(); it++)
    {
        auto& key = it->first;
        auto& value = it->second;
        std::cout << key << " = " << value << std::endl;
    }
    //Range-Based for loops with structured bindings
    for (auto [key, value] : scoreHashMap)
        std::cout << key << " = " << value << std::endl;

    //stoi() converts a String to an Integer
    int n = stoi(emptyString);

    //Implicit conversion from string to Box because there's a constructor that takes one size
    //Implicit conversion can only happen once contemporarily
    Box sizeBox = 22;

    logger.info("Test");
    std::cout << Multiply(5, 8) << std::endl;

    std::cout << "----------------------- Move Semantics --------------------" << std::endl;

    String hello = "Hello";
    //hello is moved into destHello
    //std::move is an utility function that figures the type of hello and casts it to the temporary version of that type same things as doing (String&&)
    String destHello = std::move(hello);

    //Assignment operator is only called on existing strings, so we can override it to create a move assignment operator to be used with temp values (or std::move)
    String apple = "Apple";
    String destApple;
    apple.print();
    destApple.print();

    destApple = std::move(apple);

    apple.print();
    destApple.print();

    std::cout << "----------------------- Casting ---------------------------" << std::endl;

    std::cout << "4 / 5 = " << 4 / 5 << std::endl;
    //Explicit convertion (Cast)
    std::cout << "4 / 5 = " << (float) 4 / 5 << std::endl;

    //C-Style Cast
    int castInt = 5;
    //Implicit conversion (no data loss)
    double castDouble = castInt;
    int castOtherInt = (int)(castDouble + 5.3);

    //C++ style casts (don't do anything more than C-Style casts, mainly syntactic sugar for different types of casting context)
    //Adds compile time and sometimes runtime checks to see if the conversion is valid
    //Static cast is the normal type of cast between variable types
    double castOtherDouble = static_cast<int>(castDouble) + 5.3;
    //Reinterpret cast is a cast in pointers and allows Type Punning (See section below) while still having compile time checks
    int reinterpretedInt = *reinterpret_cast<int*>(&castOtherDouble);
    //Dynamic cast checks if the object is instance of that class before performing the cast so, for example:
    Shape* shape1 = new Rectangle(5, 3);
    //if the dynamic cast fails it'll return a NULL pointer
    //Since C++ is not actually a managed language like C# it uses RTTI which is RunTime Type Information to know 
    //If an object is actually instance of a certain class, this can create a small time and space overhead and can be disabled in compiler settings
    Circle* circle1 = dynamic_cast<Circle*>(shape1);
    //Const cast is used to add or remove const from variable types
    int constCastInt = 3;
    const int& constCastIntRef = constCastInt;
    //constCastIntRef = 4; Compile-Time Error
    const_cast<int&>(constCastIntRef) = 4; //OK, because the first instance was actually a variable and not const
    const int alreadyConst = 5;
    int* alreadyConstAddress = const_cast<int*>(&alreadyConst);
    //*alreadyConstAddress = 6; //Undefined Behaviour

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

    DoubleArray(intArr, 4);
    for (int k = 0; k < 4; ++k) {
        std::cout << "Value " << k+1 << ": " << intArr[k] << std::endl;
    }

    std::cout << "-------------- Function Pointers ---------------" << std::endl;
    //Get the address of where the code of the function is stored
    //You don't need the & operator because the conversion happens implicitly
    auto func = hello_world; //the type declaration is actually: void(*)();
    IntConsumer tFunc = hello_world;
    func(8);
    tFunc(2);

    std::vector<int> vals = { 1, 2, 3, 4, 5, 6};
    for_each(vals, hello_world);

    //You can also do this with lambda function (anonymous functions)
    int extInt = 5;
    //The capture square brackets allow us to specify how external variables should be captured into the lambda to be used
    //Passing a by copy (to allow edit inside the lambda you need to make it "mutable")
    auto lambda = [extInt](int value) mutable {
        extInt *= 2;
        std::cout << "Lambda Printer: " << value << std::endl;
        std::cout << extInt;
    };
    //Whenever you use a function pointer to pass functions you can pass lambdas sorta like function literals
    //We're deferring from the actual call of the function since, we only pass the function that needs to be executed, that will be called by something else in the future
    for_each(vals, [](int value) {
        std::cout << "Lambda Printer: " << value << std::endl;
    });

    //A cool way to specify function pointers instead of raw pointers is the function class in the functional header
    std::function<bool(int)> intPredicate = [](int param){
        return param > 4;
    };

    std::vector<int> iValues = {1, 2, 3, 4, 5, 6};
    auto it = std::find_if(iValues.begin(), iValues.end(), intPredicate);
    std::cout << "first value that is greater than 4: " << *it << std::endl;

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

    //Argument Evaluation in functions might not happen in the right order, 
    //or it could produce undefined behaviour if the same variable is edited multiple times
    //
    //Since the compiler can also evaluate parameters in parallel

    std::cout << "------------------- std::array (Static Arrays) -------------------" << std::endl;

    //std::arrays are stored on the stack
    //Declare a simple integer array with a capacity of 5
    //The main  advandage of this class is that it keeps track of the length of the array automatically
    std::array<int, 5> intstarray;
    intstarray[0] = 2;
    intstarray[2] = 5;

    //In debug mode it does bounds checking

    std::cout << "------------------- std::vector (Dynamic Arrays) -------------------" << std::endl;
    
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

    //Sorting
    std::vector<int> values = { 3, 5, 2, 1, 4 };

    //std::sort is in header <algorithms>
    //Sorts in ascending order using "operator<"
    std::sort(values.begin(), values.end());
    //Based on the greater value std::greater is in header <functional>
    std::sort(values.begin(), values.end(), std::greater<>());
    //Based on a custom lambda anonymous function | Returns true if the first value is higher than the second
    // TODO: This Lambda fails a VC++ Assertion as invalid comparator
    //std::sort(values.begin(), values.end(), [](int a, int b) {
    //    if (a == 1)
    //        return false;
    //    if (b == 2)
    //        return true;
    //    return a < b;
    //});

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

    //heap allocated multi-dim array
    //Allocate 50 int pointers
    int** multiHeap = new int*[5];

    //Allocate 50 arrays
    for (int j = 0; j < 5; j++) {
        multiHeap[j] = new int[5];
    }

    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {
            multiHeap[x][y] = 2;
        }
    }

    //Allocating the arrays using a loop and heap allocation doesn't guarantee that the arrays will be allocated close together
    //which is not good because it might cause cache misses when looping over the multidim array
    //to improve that you can actually use 1D arrays to store the whole matrix
    int* flattenedMatrix = new int[5 * 5];

//    for (int j = 0; j < 5 * 5; ++j) {
//        flattenedMatrix[j] = 2;
//    }
    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {
            flattenedMatrix[y + x * 5] = 5;
        }
    }

    //To delete 2D arrays we need to loop over each pointer and delete inner arrays manually
    for (int j = 0; j < 5; j++) {
        delete[] multiHeap[j];
    }
    //And then delete the heap allocated pointers array (array of arrays)
    delete[] multiHeap;
    delete[] flattenedMatrix;

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
    //Print char array will also print all the memory near the string, since there is no terminator char in the array
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

    //String views ------------------------------------
    std::cout << "std::string_view" << std::endl;
    //Every time you construct a new std::string some memory will be heap allocated
    //even methods like substr and others that modify -> copy the string and return the new instance will all allocate new heap memory
    std::string nnname = "Name Surname";
    printString(nnname);

    //Will heap allocate a new string
    std::string ffirstNameSubString = nnname.substr(0, 4);

    //Certain times though we can use std::string_view to avoid heap allocating and just getting a pointer into an existing string allocated by someone else
    //string_view was implemented in [C++ 17] although it's a simple class to write and most people already created classes like this before it's std implementation
    std::string_view firstNameView(nnname.c_str(), 4);
    std::string_view lastNameView(nnname.c_str() + 4, 7);

    void print_string_view(const std::string_view stringView);
    print_string_view(firstNameView);
    print_string_view(lastNameView);

    //Small String Optimizations 
    //If an std::string <= than 15 chars long it is allocated on the stack instead of the heap
    std::string nick = "Davoleo";

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

        //the new keyword will call the C function malloc() which calls the specific OS function to allocate memory on the heap
        //malloc is a pretty expensice function because there is a lot that needs to be done before you get your free space on the heap
        //It's the actual allocation that is the most expensive in heap stored variables, the access is basically the same
        int* heapArray = new int[5];
        delete[] heapArray;

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
    std::cout << "height field offset in ShapeStruct: " << offsetof(ShapeStruct, height) << std::endl;

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

    std::cout << "----------------------- Structured Bindings (C++ 17) ----------------------" << std::endl;

    std::tuple<std::string, int> create_person();
    auto[structPersonName, structPersonAge] = create_person();  //Breaks the tuple in two variables and creates them automatically
    //Side note: Structured binding can also work with custom structs

    std::cout << "----------------------- std::Optional Data (C++ 17) ----------------------" << std::endl;

    std::optional<std::string> read_file_as_string(const std::string& filepath);
    std::optional<std::string> data = read_file_as_string("data.txt");

    if (data.has_value())
        std::cout << "File read successfully\n";
    else
        std::cout << "File could not be opened\n";

    //returns Either the data inside the optional of the fallback specified
    std::string stringdata = data.value_or("404: File not found");

    std::cout << "----------------------- std::Variant Data (C++ 17) ----------------------" << std::endl;
    //Variants aren't just type-safe unions because unions have a total size = to the highest of the size of the types in it
    //While variants have the sum of the sizes of all types as size (just like structs)
    //So you can actually be more efficient if you use Unions at the loss of type-checking

    std::variant<std::string, int> variantData;
    variantData = "Cherno";
    std::cout << std::get<std::string>(variantData) << std::endl;
    variantData = 2;
    if (variantData.index() == 1) {
        std::cout << std::get<int>(variantData) << std::endl;
    }
    
    std::string* val = std::get_if<std::string>(&variantData);
    if (val == nullptr) {
        std::cout << "get_if returned null pointer!" << std::endl;
    }

    std::cout << "----------------------- std::any data (C++ 17) ----------------------" << std::endl;

    //Basically std::variant that is not typesafe and can store any type of data
    //Works via unions and void pointer in the implementation
    //Will also dynamically allocate memory if the requested space is above 32bytes
    std::any anyDataTest;
    anyDataTest = 2;
    anyDataTest = "Oh Wow!";
    anyDataTest = std::string("Test");
    std::string& anyString = std::any_cast<std::string&>(anyDataTest);

    std::cout << "----------------------- Unions ----------------------" << std::endl;

    //Just like structs but only occupy the size of one member instead of the size of all members
    //in memory
    //Related to Type Punning (see the section below)
    struct Union {
        union {
            float uFloat;
            int uInt;
        };
    };

    Union un;
    un.uFloat = 2.0F;
    //Should print the value 2 in float and the representation of 2 as an int in memory
    std::cout << un.uFloat << " | " << un.uInt << std::endl;

    //You could specify multiple anonymous struct inside of a union inside of a named struct
    //to specify different ways data in the named struct can be accessed

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

    std::cout << "--------------------- Templates ----------------------" << std::endl;

    //WAY MORE powerful than generics in managed languages
    //The compiler writing code for you based on the rules you give it

    //The inferred type is probably const char* but you could also specify std::string explicitly
    //Won't work directly with const char* because the template type is not a pointer but an actual value
    templatePrint("Ciao");
    templatePrint<std::string>("Test");

    //Angular brackets can be excluded when the type can be inferred either by the parameters or by the return type
    //Template functions don't really exist, they only exist when they're called
    StackArray<std::string, 5> array;
    templatePrint(array.getSize());

    std::cout << "--------------------- Macros ----------------------" << std::endl;

    //During the preprocessing stage the macro is replaced
    WAIT;
    PRINT("Hello");

    //you can use macros to completely disable certain snippets of code
#if 0
    for (int j = 0; j < 30; ++j) {
        PRINT("spam");
    }
#endif

    std::cout << "--------------------- Namespaces ----------------------" << std::endl;
    //Is a generic statement to say that from this point on we're always using the test namespace
    //using namespace test;

    test::print("helo");

    //A way to just import the function so that it can be used without the scope operator
    using test::print;
    print("Test");

    //you can create an alias for a namespace (especially useful when namespaces are long)
    namespace t = test;
    t::print("dasadsasdsad");

    std::cout << "--------------------- Threads ----------------------" << std::endl;

    //Allow usage of s to specify time unit
    using namespace std::literals::chrono_literals;

    std::thread worker([]() {
        while (!s_finished) {
            std::cout << "Working...";
            std::this_thread::sleep_for(1s);
        }
    });

    std::cin.get();
    s_finished = true;

    //Wait on this current thready for the worker thread to finish
    worker.join();
    std::cout << "The worker Thread has finished working." << std::endl;

    //this will not run until the worker thread has finished working
    std::cin.get();

    std::cout << "--------------------- std::async & futures ----------------------" << std::endl;

    //You need to store futures or apparently work will run sequentially (because std::future destructor automatically awaits for the async function to terminate)
    std::future future1 = std::async(std::launch::async, [](){std::cout << "std::async - First" << std::endl;});
    std::future future2 = std::async(std::launch::async, [](){std::cout << "std::async - Second" << std::endl;});
    std::future future3 = std::async(std::launch::async, [](){std::cout << "std::async - Third" << std::endl;});

    std::cout << "--------------------- Chrono ----------------------" << std::endl;

    //Returns a time point of the current instant
    auto start = std::chrono::high_resolution_clock::now();

    //Sleep the current thread for 1 second to test chrono
    std::this_thread::sleep_for(1s);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;
    std::cout << "Time Passed: " << duration.count() << 's' << std::endl;

    //This function is automatically timed and prints how it takes to execute
    hello_spam();

    std::cout << "--------------------- Benchmarking ----------------------" << std::endl;

    int cnt = 0;
    {
        Timer timer("1,000,000 counting loop");
        for (int i = 0; i < 1000000; i++)
            cnt += 2;
    }

    std::cout << cnt << std::endl;

    //Tests which smart pointer is slower to be created and which is faster
    struct Vector2 
    {
        float x;
        float y;
    };

    std::cout << "Make Shared (disabled)" << std::endl;
    {
        std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
        Timer timer("make_shared_pointer");
        //for (int i = 0; i < sharedPtrs.size(); i++) 
        //    sharedPtrs[i] = std::make_shared<Vector2>();
    }


    std::cout << "new Shared (disabled)" << std::endl;
    {
        std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
        Timer timer("new_shared_pointer");
        //for (int i = 0; i < sharedPtrs.size(); i++) 
        //    sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
    }

    std::cout << "Make Unique (disabled)" << std::endl;
    {
        std::array<std::unique_ptr<Vector2>, 1000> uniquePtrs;
        Timer timer("make_unique_pointer");
        //for (int i = 0; i < uniquePtrs.size(); i++) 
        //    uniquePtrs[i] = std::make_unique<Vector2>();
    }

    //__debugbreak();


    std::cout << "--------------------- Type Punning ----------------------" << std::endl;

    //C++ has a type system and usually this system is strong but there are ways to get around it and
    //Manage memory directly (unlike Java)
    //It's useful in some cases to have raw bytes low level access but in other cases the type system is there and useful for a reason
    int sampleInt = 50;
    //Converts implicitly to a double
    double sampleIntConverted = sampleInt;
    //The int 50 is reinterpreted as a double |
    // could cause crash because of size mismatch (and we've read 8 bytes of memory when we had 4 becuase of different type size)
    // you can also use a variable alias (&) in case you don't want to create a new variable with that data
    double sampleIntReinterpreted = *(double*)&sampleInt;

    //Since structs and array are both consecutive areas of memory we can access one as each other
    struct {
        int x; int y;
    } entity = {5, 8};

    int* position = (int*)&entity;
    std::cout << position[0] << ", " << position[1] << std::endl;

    std::cout << "--------------------- ENDO ----------------------" << std::endl;

    //When There's no errors the main function should return 0
    //The main function returns 0 implicitly if you don't return anything
    return 0;
}
