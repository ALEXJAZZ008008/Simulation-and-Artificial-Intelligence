#include "NextBot.h"

NextBot::NextBot() : m_DeadCells(), m_MyCells(), m_EnemyCells(), m_Targets(), m_TemporaryChars(), m_Target(), m_Board(nullptr), m_NextBoard(nullptr), m_TimePerMove(0), m_MyId(0), m_Width(0), m_Height(0), m_Score(0), m_TemporaryScore(0), m_TemporaryBirthScore(0), m_Neighbors(0), m_MyNeighbors(0)
{

}

NextBot::NextBot(Board * const board, const int myId, const int width, const int height) : m_DeadCells(), m_MyCells(), m_EnemyCells(), m_Targets(), m_TemporaryChars(), m_Target(), m_Board(board), m_NextBoard(nullptr), m_TimePerMove(0), m_MyId(myId), m_Width(width), m_Height(height), m_Score(0), m_TemporaryScore(0), m_TemporaryBirthScore(0), m_Neighbors(0), m_MyNeighbors(0)
{

}

NextBot::NextBot(NextBot &bot) : m_DeadCells(bot.m_DeadCells), m_MyCells(bot.m_MyCells), m_EnemyCells(bot.m_EnemyCells), m_Targets(bot.m_Targets), m_TemporaryChars(bot.m_TemporaryChars), m_Target(bot.m_Target), m_Board(bot.m_Board), m_NextBoard(bot.m_NextBoard), m_TimePerMove(bot.m_TimePerMove), m_MyId(bot.m_MyId), m_Width(bot.m_Width), m_Height(bot.m_Height), m_Score(bot.m_Score), m_TemporaryScore(bot.m_TemporaryScore), m_TemporaryBirthScore(bot.m_TemporaryBirthScore), m_Neighbors(bot.m_Neighbors), m_MyNeighbors(bot.m_MyNeighbors)
{

}

NextBot & NextBot::operator = (const NextBot &bot)
{
	if (this != &bot)
	{
		m_DeadCells = bot.m_DeadCells;
		m_MyCells = bot.m_MyCells;
		m_EnemyCells = bot.m_EnemyCells;
		m_Targets = bot.m_Targets;
		m_TemporaryChars = bot.m_TemporaryChars;
		m_Target = bot.m_Target;
		m_Board = bot.m_Board;
		m_NextBoard = bot.m_NextBoard;
		m_TimePerMove = bot.m_TimePerMove;
		m_MyId = bot.m_MyId;
		m_Width = bot.m_Width;
		m_Height = bot.m_Height;
		m_Score = bot.m_Score;
		m_TemporaryScore = bot.m_TemporaryScore;
		m_TemporaryBirthScore = bot.m_TemporaryBirthScore;
		m_Neighbors = bot.m_Neighbors;
		m_MyNeighbors = bot.m_MyNeighbors;
	}

	return *this;
}

NextBot::NextBot(NextBot &&bot) : m_DeadCells(bot.m_DeadCells), m_MyCells(bot.m_MyCells), m_EnemyCells(bot.m_EnemyCells), m_Targets(bot.m_Targets), m_TemporaryChars(bot.m_TemporaryChars), m_Target(bot.m_Target), m_Board(bot.m_Board), m_NextBoard(bot.m_NextBoard), m_TimePerMove(bot.m_TimePerMove), m_MyId(bot.m_MyId), m_Width(bot.m_Width), m_Height(bot.m_Height), m_Score(bot.m_Score), m_TemporaryScore(bot.m_TemporaryScore), m_TemporaryBirthScore(bot.m_TemporaryBirthScore), m_Neighbors(bot.m_Neighbors), m_MyNeighbors(bot.m_MyNeighbors)
{

}

NextBot & NextBot::operator = (const NextBot &&bot)
{
	if (this != &bot)
	{
		m_DeadCells = bot.m_DeadCells;
		m_MyCells = bot.m_MyCells;
		m_EnemyCells = bot.m_EnemyCells;
		m_Targets = bot.m_Targets;
		m_TemporaryChars = bot.m_TemporaryChars;
		m_Target = bot.m_Target;
		m_Board = bot.m_Board;
		m_NextBoard = bot.m_NextBoard;
		m_TimePerMove = bot.m_TimePerMove;
		m_MyId = bot.m_MyId;
		m_Width = bot.m_Width;
		m_Height = bot.m_Height;
		m_Score = bot.m_Score;
		m_TemporaryScore = bot.m_TemporaryScore;
		m_TemporaryBirthScore = bot.m_TemporaryBirthScore;
		m_Neighbors = bot.m_Neighbors;
		m_MyNeighbors = bot.m_MyNeighbors;
	}

	return *this;
}

NextBot::~NextBot()
{
	delete m_Board;
	delete m_NextBoard;
}

void NextBot::UpdateCells()
{
	m_DeadCells.clear();
	m_MyCells.clear();
	m_EnemyCells.clear();

	for (unsigned int i = 0; i < m_Board->m_Field.size(); ++i)
	{
		for (int j = 0; j < m_Height; ++j)
		{
			if (m_Board->m_Field.at(i).at(j) == '.')
			{
				m_DeadCells.push_back(Coordinate(i, j));
			}
			else
			{
				if (m_Board->m_Field.at(i).at(j) == to_string(m_MyId).at(0))
				{
					m_MyCells.push_back(Coordinate(i, j));
				}
				else
				{
					if (m_Board->m_Field.at(i).at(j) == to_string((m_MyId + 1) % 2).at(0))
					{
						m_EnemyCells.push_back(Coordinate(i, j));
					}
				}
			}
		}
	}
}

void NextBot::NextTurnScore()
{
	for (int i = 0; i < m_Width; ++i)
	{
		for (int j = 0; j < m_Height; ++j)
		{
			m_Neighbors = 0;
			m_MyNeighbors = 0;

			//Middle Left
			//Top Left
			//Bottom Left
			if (i > 0)
			{
				if (m_Board->m_Field.at(i - 1).at(j) != '.')
				{
					m_Neighbors++;

					if (m_Board->m_Field.at(i - 1).at(j) == m_MyId)
					{
						m_MyNeighbors++;
					}
				}

				if (j > 0)
				{
					if (m_Board->m_Field.at(i - 1).at(j - 1) != '.')
					{
						m_Neighbors++;

						if (m_Board->m_Field.at(i - 1).at(j - 1) == m_MyId)
						{
							m_MyNeighbors++;
						}
					}
				}

				if (j < m_Height - 1)
				{
					if (m_Board->m_Field.at(i - 1).at(j + 1) != '.')
					{
						m_Neighbors++;

						if (m_Board->m_Field.at(i - 1).at(j + 1) == m_MyId)
						{
							m_MyNeighbors++;
						}
					}
				}
			}

			//Top Middle
			if (j > 0)
			{
				if (m_Board->m_Field.at(i).at(j - 1) != '.')
				{
					m_Neighbors++;

					if (m_Board->m_Field.at(i).at(j - 1) == m_MyId)
					{
						m_MyNeighbors++;
					}
				}
			}

			//Middle Right
			//Top Right
			//Bottom Right
			if (i < m_Width - 1)
			{
				if (m_Board->m_Field.at(i + 1).at(j) != '.')
				{
					m_Neighbors++;

					if (m_Board->m_Field.at(i + 1).at(j) == m_MyId)
					{
						m_MyNeighbors++;
					}
				}

				if (j > 0)
				{
					if (m_Board->m_Field.at(i + 1).at(j - 1) != '.')
					{
						m_Neighbors++;

						if (m_Board->m_Field.at(i + 1).at(j - 1) == m_MyId)
						{
							m_MyNeighbors++;
						}
					}
				}

				if (j < m_Height - 1)
				{
					if (m_Board->m_Field.at(i + 1).at(j + 1) != '.')
					{
						m_Neighbors++;

						if (m_Board->m_Field.at(i + 1).at(j + 1) == m_MyId)
						{
							m_MyNeighbors++;
						}
					}
				}
			}

			//Bottom Middle
			if (j < m_Height - 1)
			{
				if (m_Board->m_Field.at(i).at(j + 1) != '.')
				{
					m_Neighbors++;

					if (m_Board->m_Field.at(i).at(j + 1) == m_MyId)
					{
						m_MyNeighbors++;
					}
				}
			}

			if (m_Board->m_Field.at(i).at(j) != '.')
			{
				if (m_Neighbors < 2)
				{
					m_NextBoard->m_Field.at(i).at(j) = '.';
				}
				else
				{
					if (m_Neighbors > 3)
					{
						m_NextBoard->m_Field.at(i).at(j) = '.';
					}
					else
					{
						m_NextBoard->m_Field.at(i).at(j) = m_Board->m_Field.at(i).at(j);
					}
				}
			}
			else
			{
				if (m_Neighbors == 3)
				{
					if (m_MyNeighbors > 1)
					{
						m_NextBoard->m_Field.at(i).at(j) = to_string(m_MyId).at(0);
					}
					else
					{
						m_NextBoard->m_Field.at(i).at(j) = to_string((m_MyId + 1) % 2).at(0);
					}
				}
				else
				{
					m_NextBoard->m_Field.at(i).at(j) = '.';
				}
			}
		}
	}

	m_TemporaryScore = 0;

	for (int i = 0; i < m_Width; ++i)
	{
		for (int j = 0; j < m_Height; ++j)
		{
			if (m_NextBoard->m_Field.at(i).at(j) == to_string(m_MyId).at(0))
			{
				m_TemporaryScore++;
			}
			else
			{
				if (m_NextBoard->m_Field.at(i).at(j) == to_string((m_MyId + 1) % 2).at(0))
				{
					m_TemporaryScore--;
				}
			}
		}
	}
}

void NextBot::KillNextTurnScore()
{
	m_TemporaryChars.at(0) = m_Board->m_Field.at(m_Target.m_X).at(m_Target.m_Y);

	m_Board->m_Field.at(m_Target.m_X).at(m_Target.m_Y) = '.';

	NextTurnScore();

	m_Board->m_Field.at(m_Target.m_X).at(m_Target.m_Y) = m_TemporaryChars.at(0);
}

void NextBot::BirthBirthNextTurnScore()
{
	m_TemporaryChars.at(0) = m_Board->m_Field.at(m_Targets.at(0).m_X).at(m_Targets.at(0).m_Y);

	m_Board->m_Field.at(m_Targets.at(0).m_X).at(m_Targets.at(0).m_Y) = to_string(m_MyId).at(0);

	NextTurnScore();

	m_Board->m_Field.at(m_Targets.at(0).m_X).at(m_Targets.at(0).m_Y) = m_TemporaryChars.at(0);
}

void NextBot::BirthKillNextTurnScore()
{
	m_TemporaryChars.at(0) = m_Board->m_Field.at(m_Target.m_X).at(m_Target.m_Y);

	m_TemporaryChars.at(1) = m_Board->m_Field.at(m_Targets.at(0).m_X).at(m_Targets.at(0).m_Y);
	m_TemporaryChars.at(2) = m_Board->m_Field.at(m_Targets.at(1).m_X).at(m_Targets.at(1).m_Y);

	m_Board->m_Field.at(m_Target.m_X).at(m_Target.m_Y) = to_string(m_MyId).at(0);

	m_Board->m_Field.at(m_Targets.at(0).m_X).at(m_Targets.at(0).m_Y) = '.';
	m_Board->m_Field.at(m_Targets.at(1).m_X).at(m_Targets.at(1).m_Y) = '.';

	NextTurnScore();

	m_Board->m_Field.at(m_Target.m_X).at(m_Target.m_Y) = m_TemporaryChars.at(0);

	m_Board->m_Field.at(m_Targets.at(0).m_X).at(m_Targets.at(0).m_Y) = m_TemporaryChars.at(1);
	m_Board->m_Field.at(m_Targets.at(1).m_X).at(m_Targets.at(1).m_Y) = m_TemporaryChars.at(2);
}

int NextBot::Move()
{
	m_NextBoard = new Board(m_Width, m_Height);

	NextTurnScore();

	m_Score = m_TemporaryScore;

	delete m_NextBoard;

	return m_Score;

	UpdateCells();

	if (m_EnemyCells.size() > 0)
	{
		for (unsigned int j = 0; j < m_EnemyCells.size(); ++j)
		{
			m_Target = m_EnemyCells.at(j);

			KillNextTurnScore();

			if (m_TemporaryScore > m_Score)
			{
				m_Score = m_TemporaryScore;
			}
		}
	}

	if (m_MyCells.size() > 1 && m_DeadCells.size() > 0)
	{
		m_TemporaryBirthScore = -32766;

		for (unsigned int i = 0; i < m_DeadCells.size(); ++i)
		{
			m_Targets.at(0) = m_DeadCells.at(i);

			BirthBirthNextTurnScore();

			if (m_TemporaryScore > m_TemporaryBirthScore)
			{
				m_Target = m_Targets.at(0);

				m_TemporaryBirthScore = m_TemporaryScore;
			}
		}

		for (unsigned int i = 0; i < m_MyCells.size() - 1; ++i)
		{
			m_Targets.at(0) = m_MyCells.at(i);

			for (unsigned int j = i + 1; j < m_MyCells.size(); ++j)
			{
				m_Targets.at(1) = m_MyCells.at(j);

				BirthKillNextTurnScore();

				if (m_TemporaryScore > m_Score)
				{
					m_Score = m_TemporaryScore;
				}
			}
		}
	}

	delete m_NextBoard;

	return m_Score;
}