#pragma once

#include <cstdint>
#include <iostream>
#include <sstream>
#include <array>
#include "Bot.h"

using namespace std;

class Parser
{
public:
	Parser();
	explicit Parser(Bot * const);
	Parser(const Parser &);
	Parser & operator = (const Parser &);
	Parser(const Parser &&);
	Parser & operator = (const Parser &&);
	~Parser();

	string NextCmd();
	void Parse();
	void ProcessAction();
	void ProcessUpdate();
	void ProcessSettings();

	stringstream m_CMDLine;
	Bot *m_Bot;
};