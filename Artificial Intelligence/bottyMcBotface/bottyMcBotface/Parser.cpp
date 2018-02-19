#include "Parser.h"

Parser::Parser() : m_CMDLine(), m_Bot(nullptr)
{

}

Parser::Parser(Bot * const bot) : m_CMDLine(), m_Bot(bot)
{

}

Parser::Parser(const Parser &parser) : m_CMDLine(), m_Bot(parser.m_Bot)
{

}

Parser & Parser::operator = (const Parser &parser)
{
	if (this != &parser)
	{
		m_CMDLine = stringstream();
		m_Bot = parser.m_Bot;
	}

	return *this;
}

Parser::Parser(const Parser &&parser) : m_CMDLine(), m_Bot(parser.m_Bot)
{

}

Parser & Parser::operator = (const Parser &&parser)
{
	if (this != &parser)
	{
		m_CMDLine = stringstream();
		m_Bot = parser.m_Bot;
	}

	return *this;
}

Parser::~Parser()
{
	delete m_Bot;
}

string Parser::NextCmd()
{
	string input = " ";

	m_CMDLine >> input;

	return input;
}

void Parser::Parse()
{
	string input = " ";

	while (getline(cin, input))
	{
		m_CMDLine.clear();

		m_CMDLine.str(input);

		// Process command
		const string cmd = NextCmd();

		if (cmd == "action")
		{
			ProcessAction();
		}
		else
		{
			if (cmd == "update")
			{
				ProcessUpdate();
			}
			else
			{
				if (cmd == "settings")
				{
					ProcessSettings();
				}
			}
		}
	}
}

void Parser::ProcessAction()
{
	const string cmd = NextCmd();

	if (cmd == "move")
	{
		NextCmd();

		m_Bot->Move();
	}
}

void Parser::ProcessUpdate()
{
	const string update = NextCmd();

	const string cmd = NextCmd();

	if (update == "game")
	{
		if (cmd == "round")
		{
			NextCmd();
		}
		else
		{
			if (cmd == "field")
			{
				if (m_Bot->m_Board == nullptr)
				{
					m_Bot->m_Board = new Board(m_Bot->m_Width, m_Bot->m_Height);
				}

				stringstream stream(NextCmd());

				m_Bot->m_Board->UpdateBoard(stream);
			}
		}
	}
	else
	{
		if (cmd == "living_cells")
		{
			NextCmd();
		}
	}
}

void Parser::ProcessSettings()
{
	const string cmd = NextCmd();

	if (cmd == "timebank")
	{
		m_Bot->m_TimePerMove += (stoi(NextCmd()) / 100);
	}
	else
	{
		if (cmd == "time_per_move")
		{
			m_Bot->m_TimePerMove += stoi(NextCmd());
		}
		else
		{
			if (cmd == "player_names")
			{
				NextCmd();
			}
			else
			{
				if (cmd == "your_bot")
				{
					NextCmd();
				}
				else
				{
					if (cmd == "your_botid")
					{
						m_Bot->m_MyId = stoi(NextCmd());
					}
					else
					{
						if (cmd == "field_width")
						{
							m_Bot->m_Width = stoi(NextCmd());
						}
						else
						{
							if (cmd == "field_height")
							{
								m_Bot->m_Height = stoi(NextCmd());
							}
							else
							{
								if (cmd == "max_rounds")
								{
									NextCmd();
								}
							}
						}
					}
				}
			}
		}
	}
}
