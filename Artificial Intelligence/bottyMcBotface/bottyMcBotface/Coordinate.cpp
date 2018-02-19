#include "Coordinate.h"

Coordinate::Coordinate() : m_X(0), m_Y(0)
{

}

Coordinate::Coordinate(const int x, const int y) : m_X(x), m_Y(y)
{

}

Coordinate::Coordinate(const Coordinate &coordinate) : m_X(coordinate.m_X), m_Y(coordinate.m_Y)
{

}

Coordinate & Coordinate::operator = (const Coordinate &coordinate)
{
	if (this != &coordinate)
	{
		m_X = coordinate.m_X;
		m_Y = coordinate.m_Y;
	}

	return *this;
}

Coordinate::Coordinate(const Coordinate &&coordinate) : m_X(coordinate.m_X), m_Y(coordinate.m_Y)
{

}

Coordinate & Coordinate::operator = (const Coordinate &&coordinate)
{
	if (this != &coordinate)
	{
		m_X = coordinate.m_X;
		m_Y = coordinate.m_Y;
	}

	return *this;
}

Coordinate::~Coordinate()
{

}

string Coordinate::ToString() const
{
	return to_string(m_X) + "," + to_string(m_Y);
}