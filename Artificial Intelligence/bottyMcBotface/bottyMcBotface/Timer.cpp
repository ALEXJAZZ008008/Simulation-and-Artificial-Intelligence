#include "Timer.h"

Timer::Timer() : m_Begining(high_resolution_clock::now())
{

}

Timer::Timer(const Timer &timer) : m_Begining(timer.m_Begining)
{

}

Timer & Timer::operator = (const Timer &timer)
{
	if (this != &timer)
	{
		m_Begining = timer.m_Begining;
	}

	return *this;
}

Timer::Timer(const Timer &&timer) : m_Begining(timer.m_Begining)
{

}

Timer & Timer::operator = (const Timer &&timer)
{
	if (this != &timer)
	{
		m_Begining = timer.m_Begining;
	}

	return *this;
}

Timer::~Timer()
{

}

void Timer::Reset()
{
	m_Begining = high_resolution_clock::now();
}

float Timer::Elapsed() const
{
	return static_cast<float>(duration_cast<milliseconds>(high_resolution_clock::now() - m_Begining).count());
}