#include "UshirisCppExtend.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool split_error_check(const string str, const char key)
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
	if (split_error_check(str, key))
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

void cout_strs(vector<string> strs)
{
	for (auto str : strs)
	{
		cout << str << endl;
	}
}

void add_error_reason(string message)
{
	if (ERROR_REASON.front() == COMMAND_ERROR_RESON_DEFAULT)
	{
		vector<string> tmp = { message };
		ERROR_REASON = tmp;
	}
	else
	{
		ERROR_REASON.push_back(message);
	}
}

void reset_error_reason()
{
	ERROR_REASON = { COMMAND_ERROR_RESON_DEFAULT };
}

void pop_error_reason()
{
	cout_strs(ERROR_REASON);
	reset_error_reason();
}