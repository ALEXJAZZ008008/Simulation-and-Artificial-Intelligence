#include "Board.h"

Board::Board() : m_SelectedCells(), m_Field(), m_Input(" "), m_X(0), m_Y(0)
{

}

Board::Board(const int width, const int height) : m_SelectedCells(), m_Field(), m_Input(" "), m_X(0), m_Y(0)
{
	for (int i = 0; i < width; i++)
	{
		m_Field.push_back(" ");

		for (int j = 0; j < height; j++)
		{
			m_Field.at(i).push_back(' ');
		}
	}
}

Board::Board(Board &board) : m_SelectedCells(board.m_SelectedCells), m_Field(board.m_Field), m_Input(board.m_Input), m_X(board.m_X), m_Y(board.m_Y)
{

}

Board & Board::operator = (const Board &board)
{
	if (this != &board)
	{
		m_SelectedCells = board.m_SelectedCells;
		m_Field = board.m_Field;
		m_Input = board.m_Input;
		m_X = board.m_X;
		m_Y = board.m_Y;
	}

	return *this;
}

Board::Board(Board &&board) : m_SelectedCells(board.m_SelectedCells), m_Field(board.m_Field), m_Input(board.m_Input), m_X(board.m_X), m_Y(board.m_Y)
{

}

Board & Board::operator = (const Board &&board)
{
	if (this != &board)
	{
		m_SelectedCells = board.m_SelectedCells;
		m_Field = board.m_Field;
		m_Input = board.m_Input;
		m_X = board.m_X;
		m_Y = board.m_Y;
	}

	return *this;
}

Board::~Board()
{

}

void Board::UpdateBoard(stringstream &stream)
{
	m_X = 0;
	m_Y = 0;

	m_Input = " ";

	while (getline(stream, m_Input, ','))
	{
		m_Field.at(m_X).at(m_Y) = m_Input.at(0);

		m_X = (m_X + 1) % m_Field.size();

		if (m_X == 0)
		{
			m_Y++;
		}
	}
}