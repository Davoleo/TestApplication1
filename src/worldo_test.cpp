#include <iostream>
#include <thread>
#include "timer.h"

#define PROFILING 1

#if PROFILING
#define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name);
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
#else
#define PROFILE_SCOPE(name)
#endif

void thousand_isekais() {
    PROFILE_FUNCTION();
    for(int i = 0; i < 1000; i++)
        std::cout << "Hello Warudo N°" << i << std::endl;
}

void thousand_squared_isekais() {
    PROFILE_FUNCTION();
    for(int i = 0; i < 1000; i++)
        std::cout << "Hello Warudo N°" << sqrt(i) << std::endl;
}

void run_benchmarks() {

    PROFILE_FUNCTION();

    std::cout << "Running Benchmarks...\n";
    
    std::thread a([]() { 
        thousand_isekais(); 
    });
    
    thousand_isekais();
    thousand_squared_isekais();

    a.join();
}

int section_world_test() {

    JsonInstrumentor::get().begin_session("Worldo Profile");

    run_benchmarks();

    JsonInstrumentor::get().end_session();

	return 0;
}