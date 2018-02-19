#pragma once

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

class Timer
{
public:
	Timer();
	Timer(const Timer &);
	Timer & operator = (const Timer &);
	Timer(const Timer &&);
	Timer & operator = (const Timer &&);
	~Timer();

	void Reset();
	float Elapsed() const;

	time_point<high_resolution_clock> m_Begining;
};