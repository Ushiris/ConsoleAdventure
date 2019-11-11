#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::multimap;
using std::map;
using std::pair;

enum CommandMean:int
{
	echo,
	app_exit,
	no,
	comment,
	commentEnd,
	error_ushiris,
}; 


class CommandSystem
{
public:
	multimap<CommandMean, string> dictionaly;
	map<string, bool> def_flags =
	{
	{"text",false},
	{"hide",true},
	{"showed",false},
	{"last",false},
	{"beginText",false}
	};
	int skip = 0;
	map<string, bool> flags;

	const vector<std::pair<CommandMean, string>> command_list =
	{
	{echo,"echo"},
	{echo,"�R�}���h�\��"},
	{app_exit,"exit"},
	{app_exit,"�I��"},
	{app_exit,"����"},
	{app_exit,"���O�A�E�g"},
	{no,"no"},
	{no,"ignore"},
	{no,"����"},
	{comment,"c["},
	{comment,"��"},
	{commentEnd,"]c"},
	{commentEnd,"����"},
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
		flags = def_flags;
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

	void reset_flags()
	{
		flags = def_flags;
		skip = 0;
	}

};