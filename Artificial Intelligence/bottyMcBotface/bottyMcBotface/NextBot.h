#pragma once

#include <iostream>
#include <stdio.h>
#include <array>
#include <vector>
#include <algorithm>
#include "NextBot.h"
#include "Board.h"
#include "Coordinate.h"

using namespace std;

class NextBot
{
public:
	NextBot();
	NextBot(Board *, const int, const int, const int);
	NextBot(NextBot &);
	NextBot & operator = (const NextBot &);
	NextBot(NextBot &&);
	NextBot & operator = (const NextBot &&);
	~NextBot();

	// Action
	void UpdateCells();
	void NextTurnScore();
	void KillNextTurnScore();
	void BirthBirthNextTurnScore();
	void BirthKillNextTurnScore();
	int Move();

	vector<Coordinate> m_DeadCells, m_MyCells, m_EnemyCells;
	array<Coordinate, 2> m_Targets;
	array<char, 3> m_TemporaryChars;
	Coordinate m_Target;
	Board *m_Board;
	Board *m_NextBoard;
	int m_TimePerMove, m_MyId, m_Width, m_Height, m_Score, m_TemporaryScore, m_TemporaryBirthScore, m_Neighbors, m_MyNeighbors;
};