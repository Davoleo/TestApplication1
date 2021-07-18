//
// Created by Davoleo on 02/05/2021.
//

#include <chrono>

#include "instrumentor.h"

#ifndef TESTAPPLICATION1_TIMER_H
#define TESTAPPLICATION1_TIMER_H

struct Timer {

private:
    const char* name;
    bool stopped;
    std::chrono::duration<float> duration;
    //Note: MinGW needs system_clock as a type instead of steady_clock
    std::chrono::time_point<std::chrono::high_resolution_clock> startTimePoint;

public:
    Timer(const char* name): name(name), stopped(false) {
        startTimePoint = std::chrono::high_resolution_clock::now();
    }

    virtual ~Timer() {
        if (!stopped)
            stop();
    }

    virtual void stop() 
    {
        auto endTimePoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimePoint).time_since_epoch().count();
        auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

        stopped = true;

        long long duration = stop - start;
        float ms = duration * 0.001;
        std::cout << name << " Timer Took " << duration << "\xCE\xBCs (" << ms << "ms)" << std::endl;
    }
};

#endif //TESTAPPLICATION1_TIMER_H
