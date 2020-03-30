#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "UshirisCppExtend.h"
#include "Action.h"
#include "Commands.h"

using std::cin;
using std::cout;
using std::endl;
using namespace Ushiris::Command;

constexpr char COMMAND_SPLIT_KEY = ' ';

CommandSystem Csys;

vector<string> command_input(char key)
{
	vector<string> commands;
	string str;

	std::getline(cin, str);
	commands = split(str, key);

	return commands;
}

//command‚ÌŽÀ‘••”•ª
void command_run(vector<string> commands)
{
	bool isTextBegin = true;

	for (unsigned int i = 0;i < commands.size();i++)
	{
		//errors
		if (commands[i] == COMMAND_ERROR_MESSAGE)
		{
			cout << "command error:" << endl;
			pop_error_reason();
			break;
		}

		//last check
		if (i >= commands.size() - 1)
		{
			Csys.flags.at("last") = true;
		}

		//plain text
		if (Csys.IsMeaning(commands[i], commentEnd) && Csys.flags.at("text"))
		{
			Csys.flags.at("text") = false;
			cout << "\"" << endl;
			continue;
		}
		else if (Csys.flags.at("text"))
		{
			if (Csys.flags.at("last"))
			{
				cout << "Command warning:Not end comment" << endl;
			}
			cout << (Csys.flags.at("beginText") ? "" : " ") << commands[i];
			Csys.flags.at("beginText") = false;
			continue;
		}

		//skip commands
		if (Csys.skip)
		{
			Csys.skip--;
			continue;
		}
		if (Csys.IsMeaning(commands[i], no))
		{
			Csys.skip++;
			continue;
		}

		//effects
		if (Csys.IsMeaning(commands[i], echo) && !Csys.flags.at("showed"))
		{
			command_echo(commands);
			Csys.flags.at("showed") = true;
		}
		else if (Csys.IsMeaning(commands[i], app_exit))
		{
			exit_adv(0);
		}
		else if (Csys.IsMeaning(commands[i], comment))
		{
			Csys.flags.at("text") = true;
			Csys.flags.at("beginText") = true;
			cout << "\"";
		}
	}

	Csys.reset_flags();
	cout << endl;
}


int main(void)
{
	Csys.setup();

	while (true)
	{
		vector<string> commands;
		commands = command_input(COMMAND_SPLIT_KEY);
		command_run(commands);
	}

	return 0;
}