#pragma once
#include <string>
#include <vector>

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
	using std::string;

	multimap<CommandMean, string> dictionaly;
	map<string, bool> flags =
	{
	{"text",false},
	{"hide",true},
	{"showed",false},
	{"last",false}
	};

	const vector<std::pair<CommandMean, string>> command_list =
	{
	{echo,"echo"},
	{app_exit,"exit"},
	{no,"no"},
	{comment,"c["},
	{commentEnd,"]c"}
	};

	void add_command(std::pair<CommandMean, string> comm)
	{
		dictionaly.insert(comm);
	}

	void setup()
	{
		for (const auto comm : command_list)
		{
			add_command(comm);
		}
	}

	bool IsMeaning(string input, CommandMean mean)
	{
		auto values = dictionaly.equal_range(mean);

		if (values.first == dictionaly.end())
		{
			return false;
		}

		for (;values.first != values.second;++values.first)
		{
			if (values.first->second == input)
			{
				return true;
			}
		}

		return false;
	}
}