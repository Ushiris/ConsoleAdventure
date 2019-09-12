#include "Action.h"
#include <iostream>

using namespace std;

void exit_adv(int return_code)
{
	exit(return_code);
}

void command_echo(vector<string> commands)
{
	bool isBegin = true;
	for (const auto str : commands)
	{
		cout << (isBegin ? "" : "/") << str;
		isBegin = false;
	}
	cout << endl;
}