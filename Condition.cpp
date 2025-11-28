
#include "Condition.h"
#include "GUI\UI_Info.h"

Condition::Condition(Point T, const string &lhs, const string &comp, const string &rhs)
{
	Top = T;
	width = UI.ASSGN_WDTH;
	height = UI.ASSGN_HI;
	LHS = lhs;
	Comp = comp;
	RHS = rhs;
	Selected = false;
	UpdateStatementText();
}

void Condition::UpdateStatementText()
{
	Text = LHS + " " + Comp + " " + RHS;
}

void Condition::Draw(Output* pOut) const
{
	pOut->DrawCondtionalStat(Top, width, height, Text, Selected);
}