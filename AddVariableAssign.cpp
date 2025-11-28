#include "AddVariableAssign.h"

// Original Includes from your project:
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\GUI\UI_Info.h"

#include <sstream>
using namespace std;

// constructor: sets the ApplicationManager pointer inside this action
AddVariableAssign::AddVariableAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{
    LHS = "";
    RHS = "";
}

void AddVariableAssign::ReadActionParameters()
{
    Input* pIn = pManager->GetInput();
    Output* pOut = pManager->GetOutput();

    // Read the (Position) parameter
    pOut->PrintMessage("Variable Assignment Statement: Click to add the statement");
    pIn->GetPointClicked(Position);
    pOut->ClearStatusBar();

    // DONE: Ask the user in the status bar to enter the LHS and set the data member
    pOut->PrintMessage("Variable Assignment: Enter Left Hand Side (Variable Name):");
    LHS = pIn->GetVariable(pOut);

    // DONE: Ask the user in the status bar to enter the RHS and set the data member
    pOut->PrintMessage("Variable Assignment: Enter Right Hand Side (Variable Name):");
    RHS = pIn->GetVariable(pOut);

    pOut->ClearStatusBar();
}

void AddVariableAssign::Execute()
{
    // 1. Read the required parameters (Position, LHS, RHS) from the user
    ReadActionParameters();

    // 2. Calculate the Left Corner of the assignment statement block
    Point Corner;
    // The position is usually the center, so calculate the top-left corner
    Corner.x = Position.x - UI.ASSGN_WDTH / 2;
    Corner.y = Position.y;

    // 3. Create a new VariableAssign object using the collected parameters
    VariableAssign* pAssign = new VariableAssign(Corner, LHS, RHS);

    // 4. Add the created statement to the Application Manager's statement list
    pManager->AddStatement(pAssign);
}
