#pragma once

#include <iostream>
#include <string>
#include <vector>

constexpr auto COMMAND_MAX_LENGTH = 999;
constexpr auto COMMAND_ERROR_MESSAGE = "Error ! ! ! ! !";

using namespace std;

bool splitErrorCheck(const string str,const char key)
{
	if (str.length() == 0)
	{
		cout << "String error:Null" << endl;
		return true;
	}

	if (str.length() >= COMMAND_MAX_LENGTH)
	{
		cout << "String error:Too long" << endl;
		return true;
	}

	if (str.back() == key)
	{
		cout << "String error:Back is \'" << key << '\'' << endl;
	}

	bool isBlank = true;
	for (const auto &ch : str)
	{
		if (ch != key)
		{
			isBlank = false;
			break;
		}
	}
	if (isBlank)
	{
		cout << "String error:Is \'" << key << "\' only string" << endl;
	}
	return isBlank;
}

vector<string> split(const string str, const char key)
{
	if (splitErrorCheck(str, key))
	{
		return vector<string>(1, COMMAND_ERROR_MESSAGE);
	}

	vector<string> result;

	unsigned int index = 0;
	while (str.find(key, index) != string::npos)
	{
		string word = str.substr(index, str.find(key, index) - index);
		result.push_back(word);
		index = str.find(key, index) + 1;
	}
	result.push_back(str.substr(index, str.length()));

	return result;
}
