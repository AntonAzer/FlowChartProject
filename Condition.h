
#ifndef CONDITION_H
#define CONDITION_H
#include <string>

#include "Statements/Statement.h"

class Condition : public Statement
{
private:
	Point Top; // top vertex of diamond
	int width, height;
	string LHS, Comp, RHS;

	virtual void UpdateStatementText();

public:
	Condition(Point T, const string &lhs, const string &comp, const string &rhs);

	virtual void Draw(Output* pOut) const;
};

#endif