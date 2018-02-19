#pragma once

#include <iostream>
#include <stdio.h>
#include <array>
#include <vector>
#include <algorithm>
#include "Timer.h"
#include "NextBot.h"
#include "Board.h"
#include "Coordinate.h"

using namespace std;

class Bot
{
public:
	Bot();
	Bot(Bot &);
	Bot & operator = (const Bot &);
	Bot(Bot &&);
	Bot & operator = (const Bot &&);
	~Bot();

	// Action
	void UpdateCells();
	void NextTurnScore();
	void KillNextTurnScore();
	void BirthBirthNextTurnScore();
	void BirthKillNextTurnScore();
	void Move();

	vector<Coordinate> m_DeadCells, m_MyCells, m_EnemyCells;
	array<Coordinate, 2> m_Targets;
	array<char, 3> m_TemporaryChars;
	Timer m_Timer;
	Coordinate m_Target;
	string m_Output;
	NextBot *m_NextBot;
	Board *m_Board;
	Board *m_NextBoard;
	int m_TimePerMove, m_MyId, m_Width, m_Height, m_Score, m_TemporaryScore, m_TemporaryBirthScore, m_Neighbors, m_MyNeighbors;
};