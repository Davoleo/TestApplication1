//
// Created by Davoleo on 02/05/2021.
//

#include <chrono>

#ifndef TESTAPPLICATION1_TIMER_H
#define TESTAPPLICATION1_TIMER_H

struct Timer {

    std::chrono::duration<float> duration;
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;

    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000;
        std::cout << "Timer Took " << ms << "ms" << std::endl;
    }
};

#endif //TESTAPPLICATION1_TIMER_H
