#pragma once

#include <sstream>
#include <vector>
#include "Coordinate.h"

using namespace std;

class Board
{
public:
	Board();
	Board(const int, const int);
	Board(Board &);
	Board & operator = (const Board &);
	Board(Board &&);
	Board & operator = (const Board &&);
	~Board();

	void UpdateBoard(stringstream &);

	vector<Coordinate> m_SelectedCells;
	vector<string> m_Field;
	string m_Input;
	int m_X, m_Y;
};