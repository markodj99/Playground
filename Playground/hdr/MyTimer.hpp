#pragma once
#include <iostream>
#include <chrono>

namespace mystd
{
	class Timer
	{
	private:
		std::chrono::time_point<std::chrono::steady_clock> start;
		std::chrono::time_point<std::chrono::steady_clock> end;
		const char* name;
	public:
		Timer() = delete;
		Timer(const char* name);
		Timer(const Timer& other) = delete;
		Timer(Timer&& other) = delete;
		~Timer();

		Timer& operator=(const char* name) = delete;
		Timer& operator=(const Timer& other) = delete;
		Timer& operator=(Timer&& other) = delete;
	};

	Timer::Timer(const char* name) : name(name) 
	{
		start = std::chrono::high_resolution_clock::now();
	}

	Timer::~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;
		
		double ms = duration.count() * 1000.0f;
		std::cout << "Timer " << name << " : " << ms << " ms" << std::endl;;
	}
}