#include "AddCondition.h"
#include "ApplicationManager.h"
#include "Condition.h"
#include "Actions/Action.h"

AddCondition::AddCondition(ApplicationManager *pAppManager) : Action(pAppManager)
{
}

void AddCondition::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Conditional Statement: Click to add the statement");
	pIn->GetPointClicked(Position);

	// Read LHS (variable)
	pOut->PrintMessage("Enter LHS variable name:");
	LHS = pIn->GetVariable(pOut); // GetVariable validates variable

	// Read comparison operator
	pOut->PrintMessage("Enter comparison operator (==, !=, <, <=, >, >=):");
	Comp = pIn->GetCompOperator(pOut); // uses Input helper for comparator

	// Read RHS (value or variable) and validate using HelperFn
	pOut->PrintMessage("Enter RHS (variable or value):");
	RHS = pIn->GetString(pOut);
	while (ValueOrVariable(RHS) == INVALID_OP)
	{
		pOut->PrintMessage("Invalid RHS. Enter a variable name or numeric value:");
		RHS = pIn->GetString(pOut);
	}

	pOut->ClearStatusBar();
}

void AddCondition::Execute()
{
	ReadActionParameters();

	Condition* pCond = new Condition(Position, LHS, Comp, RHS);
	pManager->AddStatement(pCond);
}