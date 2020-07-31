//
// Created by Davoleo on 31/07/2020.
//

#ifndef TESTAPPLICATION1_LOGGER_H
#define TESTAPPLICATION1_LOGGER_H


#include <iostream>

class Logger {
public:
    enum Level {
        ERROR = 0,
        WARNING,
        INFO
    };

    //Members
private:
    Level mLogLevel = INFO;

    //Methods
public:
    void setLevel(Level level) {
        mLogLevel = level;
    }

    void error(const char* message) {
        if (mLogLevel >= ERROR)
            std::cout << "[ERROR]: " << message << std::endl;
    }

    void warn(const char* message) {
        if (mLogLevel >= WARNING)
            std::cout << "[WARNING]: " << message << std::endl;
    }

    void info(const char* message) {
        if (mLogLevel >= INFO)
            std::cout << "[INFO]: " << message << std::endl;
    }
};


#endif //TESTAPPLICATION1_LOGGER_H
