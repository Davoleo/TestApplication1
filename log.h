//
// Created by Davoleo on 23/06/2020.
//
//Preprocess command (means: only include this header file once IN A SINGLE FILE)
//#pragma once
//Another classic way of writing headers guards is:
#ifndef _LOG_H
#define _LOG_H
//if _LOG_H is NOT defined then define it, otherwise skip the code block entirely

//Used to:
//- declare certain types of functions

//To avoid linking errors when including this header file in mulitple cpp files we could:
//- Make this function static (hence only usable internally in the file) [which means every cpp file will have its own version of the Log Function]
//- Make this function inline (the function call will be replaced with it's body content)
//- Move the function definition to another file
void Log(const char* message);

#endif