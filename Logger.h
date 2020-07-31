//
// Created by Davoleo on 31/07/2020.
//

#ifndef TESTAPPLICATION1_LOGGER_H
#define TESTAPPLICATION1_LOGGER_H


#include <iostream>

class Logger {
public:
    const int LOG_LEVEL_ERROR = 0;
    const int LOG_LEVEL_WARNING = 1;
    const int LOG_LEVEL_INFO = 2;
    //Members
private:
    int mLogLevel = LOG_LEVEL_INFO;

    //Methods
public:
    void setLevel(int level) {
        mLogLevel = level;
    }

    void error(const char* message) {
        if (mLogLevel >= LOG_LEVEL_ERROR)
            std::cout << "[ERROR]: " << message << std::endl;
    }

    void warn(const char* message) {
        if (mLogLevel >= LOG_LEVEL_WARNING)
            std::cout << "[WARNING]: " << message << std::endl;
    }

    void info(const char* message) {
        if (mLogLevel >= LOG_LEVEL_INFO)
            std::cout << "[INFO]: " << message << std::endl;
    }
};


#endif //TESTAPPLICATION1_LOGGER_H
