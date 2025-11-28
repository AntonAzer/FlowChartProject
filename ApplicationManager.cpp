#include "ApplicationManager.h"
#include "Actions\AddValueAssign.h"
#include "Actions\AddStart.h"
#include "Actions\AddEnd.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	StatCount = 0;
	ConnCount = 0;
	pSelectedStat = NULL;	//no Statement is selected yet
	pClipboard = NULL;

	//Create an array of Statement pointers and set them to NULL		
	for (int i = 0; i < MaxCount; i++)
	{
		StatList[i] = NULL;
		ConnList[i] = NULL;
	}
}

//Destructor: free allocated resources
ApplicationManager::~ApplicationManager()
{
	// Delete all statements
	for (int i = 0; i < StatCount; ++i)
	{
		delete StatList[i];
		StatList[i] = NULL;
	}
	StatCount = 0;

	// Delete all connectors (if any)
	for (int i = 0; i < ConnCount; ++i)
	{
		delete ConnList[i];
		ConnList[i] = NULL;
	}
	ConnCount = 0;

	// Delete input and output objects
	delete pIn; pIn = NULL;
	delete pOut; pOut = NULL;
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//


ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to ActioType, create the corresponding action object
	switch (ActType)
	{
	case ADD_VALUE_ASSIGN:
		pAct = new AddValueAssign(this);
		break;

	case ADD_START:
		pAct = new AddStart(this);
		break;

	case ADD_END:
		pAct = new AddEnd(this);
		break;

	case ADD_CONDITION:
		///create AddCondition Action here

		break;

	case SELECT:
		///create Select Action here

		break;

	case EXIT:
		///create Exit Action here

		break;

	case STATUS:
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}


//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//

//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement* pStat)
{
	if (StatCount < MaxCount)
		StatList[StatCount++] = pStat;
}

////////////////////////////////////////////////////////////////////////////////////
//Return the selected statement
Statement* ApplicationManager::GetSelectedStatement() const
{
	return pSelectedStat;
}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement* pStat)
{
	pSelectedStat = pStat;
}

////////////////////////////////////////////////////////////////////////////////////
//Returns the Clipboard
Statement* ApplicationManager::GetClipboard() const
{
	return pClipboard;
}

////////////////////////////////////////////////////////////////////////////////////
//Set the Clipboard
void ApplicationManager::SetClipboard(Statement* pStat)
{
	pClipboard = pStat;
}


////////////////////////////////////////////////////////////////////////////////////
// Return pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}

////////////////////////////////////////////////////////////////////////////////////
// Return pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}

////////////////////////////////////////////////////////////////////////////////////
// Redraws all the drawing window
void ApplicationManager::UpdateInterface() const
{
	// Clear drawing area first
	if (pOut)
		pOut->ClearDrawArea();

	// Draw all statements
	for (int i = 0; i < StatCount; ++i)
	{
		if (StatList[i] != NULL)
			StatList[i]->Draw(pOut);
	}

	// If you have connectors drawing implemented later, draw them here.
}