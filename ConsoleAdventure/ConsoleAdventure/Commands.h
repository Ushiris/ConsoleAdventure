#pragma once
#include <string>
#include <vector>

#define ADD_COMMAND( str ) const string str=#str; CommandStringList.push_back( #str ); 

using std::string;

namespace CommandString
{
	vector<string> CommandStringList;

	void CreateCommandStringList()
	{
		ADD_COMMAND(echo);
	}

	const string
		echo = "echo",
		exit = "exit",
		no = "no",
		comment = "comment|",
		cEnd = "|",
		error = "Error",
		jp_echo = "表示",
		jp_exit = "終了",
		jp_comment = "コメント（",
		jp_cEnd = "）";
}

using namespace CommandString;

class CommandCompiler
{
public:
	enum CommandMean
	{
		echo,
		exit,
		no,
		comment,
		cEnd,
	};

	CommandCompiler();
	~CommandCompiler();

	static CommandMean CommandCompile(string command_str)
	{

	}

private:
	map<string, CommandMean> CommandDictionary;

};

CommandCompiler::CommandCompiler()
{
}

CommandCompiler::~CommandCompiler()
{
}