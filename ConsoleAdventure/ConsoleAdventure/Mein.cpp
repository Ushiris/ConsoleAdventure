#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "UshirisCppExtend.h"
#include "Action.h"
#include "Commands.h"

using namespace std;
using namespace CommandSystem;

constexpr auto COMMAND_SPLIT_KEY = ' ';

vector<string> command_input(char key)
{
	vector<string> commands;
	string str;

	getline(cin, str);
	commands = split(str, key);

	return commands;
}

//command‚ÌŽÀ‘••”•ª
void command_run(vector<string> commands)
{
	int skip = 0;
	bool isTextBegin = true;

	unsigned int idx = 0;
	for(const auto &word:commands)
	{
		//errors
		if (word == COMMAND_ERROR_MESSAGE)
		{
			cout << "Error!" << endl;
			break;
		}

		//last check
		if (idx >= commands.size() - 1)
		{
			flags.at("last") = true;
		}

		//plain text
		if (IsMeaning(word,commentEnd) && flags.at("text"))
		{
			flags.at("text") = false;
			cout << "\"" << endl;
			continue;
		}
		else if (flags.at("text"))
		{
			if (flags.at("last"))
			{
				cout << "Command warning:Not end comment"<< endl;
			}
			cout << (isTextBegin ? "" : " ") << word;
			isTextBegin = false;
			continue;
		}

		//skip commands
		if (skip)
		{
			skip--;
			continue;
		}
		if (IsMeaning(word,no))
		{
			skip++;
			continue;
		}
		
		//effects
		if (IsMeaning(word,echo) && !flags.at("showed"))
		{
			command_echo(commands);
			flags.at("showed") = true;
		}
		else if (IsMeaning(word,app_exit))
		{
			exit_adv(0);
		}
		else if (IsMeaning(word,comment))
		{
			flags.at("text") = true;
			isTextBegin = true;
			cout << "\"";
		}

		idx++;
	}

	cout << endl;
}


int main(void)
{
	CommandSystem::setup();
	cout << "setup successed!" << endl;

	while (true)
	{
		vector<string> commands;
		commands = command_input(COMMAND_SPLIT_KEY);
		command_run(commands);
	}

	return 0;
}