#pragma once
#include <string>
#include <vector>

using std::string;

enum CommandMean:int
{
	echo,
	app_exit,
	no,
	comment,
	commentEnd,
	error_ushiris,
}; 

namespace CommandSystem
{
	vector<string> CommandStringList;

	const vector<std::pair<CommandMean,string>> command_list=
	{
	{echo,"echo"},
	{app_exit,"exit"},
	{no,"no"},
	{comment,"c["},
	{commentEnd,"]c"}
	};

	void setup()
	{
		for (const auto comm : command_list)
		{
			add_command(comm);
		}
	}

	void add_command(CommandMean mean,string command)
	{
		dictionaly.insert(std::pair<CommandMean, string>(mean, command));
	}

	void add_command(std::pair<CommandMean, string> comm)
	{
		dictionaly.insert(comm);
	}

	multimap<CommandMean,string> dictionaly;
}