#pragma once

#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <thread>

#include "timer.h"

struct ProfilingResults {
	std::string name;
	long long start, end;
	uint32_t threadID;
};

struct InstrumentationSession {
	std::string name;
};

class JsonInstrumentor {
private:
	InstrumentationSession* currentSession;
	std::ofstream fOutput;
	int profileCount;

public:
	JsonInstrumentor(): currentSession(nullptr), profileCount(0) {
	}

	void begin_session(const std::string& name, const std::string& filepath = "results.json") {
		fOutput.open(filepath);
		write_header();
		currentSession = new InstrumentationSession{ name };
	}

	void end_session() {
		write_footer();
		fOutput.close();
		delete currentSession;
		currentSession = nullptr;
		profileCount = 0;
	}

	void write_profile(const ProfilingResults& result) {
		if (profileCount++ > 0)
			fOutput << ',';

		std::string name = result.name;
		//Replace all double quotes with single quotes because double quotes break JSON
		std::replace(name.begin(), name.end(), '"', '\'');

		fOutput << '{';
		fOutput << R"("cat": "function",)";
		fOutput << "\"dur\": " << (result.end - result.start) << ',';
		fOutput << "\"name\": \"" << name << "\",";
		fOutput << "\"ph\": \"X\",";
		fOutput << "\"pid\": 0,";
		fOutput << "\"tid\": " << result.threadID << ",";
		fOutput << "\"ts\": " << result.start;
		fOutput << '}';

		//Flushing each time we write allows us to stream content so in case something crash all the data is not lost
		fOutput.flush();
	}

	void write_header() {
		fOutput << R"({"otherData": {}, "traceEvents": [)";
		fOutput.flush();
	}

	void write_footer() {
		fOutput << "]}";
		fOutput.flush();
	}

	static JsonInstrumentor& get() {
		static JsonInstrumentor* instance = new JsonInstrumentor();
		return *instance;
	}

};

class InstrumentationTimer
{
private:
    const char* name;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTimepoint;
    bool stopped;

public:
    InstrumentationTimer(const char* name)
        : name(name), stopped(false)
    {
        startTimepoint = std::chrono::high_resolution_clock::now();
    }

    ~InstrumentationTimer()
    {
        if (!stopped)
            Stop();
    }

    void Stop()
    {
        auto endTimepoint = std::chrono::high_resolution_clock::now();

        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimepoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

        uint32_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());
        JsonInstrumentor::get().write_profile({ name, start, end, threadID });

        stopped = true;
    }
};