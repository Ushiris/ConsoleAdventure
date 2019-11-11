#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

const int COMMAND_MAX_LENGTH = 999;
const string COMMAND_ERROR_MESSAGE = "Error ! ! ! ! !";
const string COMMAND_ERROR_RESON_DEFAULT = "undifined";
vector<string> ERROR_REASON = { COMMAND_ERROR_RESON_DEFAULT };

bool split_error_check(const string str, const char key);

vector<string> split(const string str, const char key);

void cout_strs(vector<string> strs);

void add_error_reason(string message);

void reset_error_reason();

void pop_error_reason();