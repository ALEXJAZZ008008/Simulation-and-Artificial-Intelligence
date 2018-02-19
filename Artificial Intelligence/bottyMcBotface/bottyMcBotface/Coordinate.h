#pragma once

#include <iostream>
#include <sstream>
#include <stdio.h>

using namespace std;

class Coordinate
{
public:
	Coordinate();
	Coordinate(const int, const int);
	Coordinate(const Coordinate &);
	Coordinate & operator = (const Coordinate &);
	Coordinate(const Coordinate &&);
	Coordinate & operator = (const Coordinate &&);
	~Coordinate();

	string ToString() const;

	int m_X, m_Y;
};