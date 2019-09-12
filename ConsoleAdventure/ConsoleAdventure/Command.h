#pragma once
#include <string>

using std::string;

class Command
{
private:
	string name;
	void behaver(string input);
	bool isRunable();

public:
	Command();
	~Command();
};

