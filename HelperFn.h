#pragma once

#include <string>
using namespace std;

enum OpType
{
	VALUE_OP,
	VARIABLE_OP,
	INVALID_OP
};

bool IsValue (string input);
bool IsVariable (string input);
OpType ValueOrVariable (string input);
