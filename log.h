//
// Created by Davoleo on 23/06/2020.
//

#include <iostream>

//To avoid linking errors when including this header file in mulitple cpp files we could:
//- Make this function static (hence only usable internally in the file) [which means every cpp file will have its own version of the Log Function]
//- Make this function inline (the function call will be replaced with it's body content)
//- Move the function definition to another file
void Log(const char* message);