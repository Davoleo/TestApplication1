//
// Created by Davoleo on 02/05/2021.
//

#include <chrono>

#ifndef TESTAPPLICATION1_TIMER_H
#define TESTAPPLICATION1_TIMER_H

struct Timer {

    std::chrono::duration<float> duration;
    //Note: MinGW needs system_clock as a type instead of steady_clock
    std::chrono::time_point<std::chrono::high_resolution_clock> startTimePoint;

public:
    Timer() {
        startTimePoint = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        stop();

        auto endTimePoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimePoint).time_since_epoch().count();
        auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

        long long duration = stop - start;
        float ms = duration * 0.001;
        std::cout << "Timer Took " << duration << "\xCE\xBCs (" << ms << "ms)" << std::endl;
    }

    void stop() 
    {

    }
};

#endif //TESTAPPLICATION1_TIMER_H
