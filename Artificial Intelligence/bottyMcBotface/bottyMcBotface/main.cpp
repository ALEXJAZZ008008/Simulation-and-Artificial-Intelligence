#include <cstdint>
#include "Parser.h"
#include "Bot.h"

int main()
{
	Bot *bot = new Bot();

	Parser parser = Parser(bot);
	parser.Parse();

	if (bot != nullptr)
	{
		delete bot;

		bot = nullptr;
	}

	return 0;
}
