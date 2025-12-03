#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

#include "Actions\AddValueAssign.h"
#include "Actions\AddVariableAssign.h"
#include "Actions\AddOperationAssign.h"
#include "Actions\AddRead.h"
#include "Actions\AddWrite.h"
#include "Actions\AddStart.h"
#include "Actions\AddEnd.h"
#include "Actions\AddDeclare.h"
#include "Actions\AddCondition.h"
#include"Actions\AddConnector.h"
#include"Actions\Select.h"
#include "Actions\Edit.h"
#include "Actions\Delete.h"
#include "Actions\Cut.h"
#include "Actions\Copy.h"
#include "Actions\Paste.h"
#include "Actions\Save.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	StatCount = 0;
	ConnCount = 0;
	pSelectedStat = NULL;	//no Statement is selected yet
	pSelectedConn=NULL;      //no connector is selected yet
	pClipboard = NULL;
	
	//Create an array of Statement pointers and set them to NULL		
	for(int i=0; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
	}
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
	
		case ADD_VAR_ASSIGN:
			pAct = new AddVariableAssign(this);
			break;


		case ADD_OPER_ASSIGN:
			pAct = new AddOperationAssign(this);
			break;

		case ADD_READ:
			pAct = new AddRead(this);
			break;

		case ADD_WRITE:
			pAct = new AddWrite(this);
			break;

		case ADD_START:
			pAct = new AddStart(this);
			break;

		case ADD_END:
			pAct = new AddEnd(this);
			break;

		case ADD_DECLARE_VARIABLE:
			pAct = new AddDeclare(this);
			break;

			
		case ADD_CONDITION:
			pAct = new AddCondition(this);
			break;

		case ADD_CONNECTOR:
			pAct = new AddConnector(this);
			break;

		case SELECT:
			pAct = new Select(this);
			break;

		case EDIT_STAT:
			pAct = new Edit(this);
			break;
			
		case DEL:
			pAct = new Delete(this);
			break;
		case COPY:
			pAct = new Copy(this);
			break;
		case CUT:
			pAct = new Cut(this);
			break;
		case PASTE:
			pAct = new Paste(this);
			break;
		case SAVE:
			pAct = new Save(this);
			break;

		case EXIT:
			///create Exit Action here
			
			break;
	
		case STATUS:
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}



//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//


//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	if(StatCount < MaxCount)
		StatList[StatCount++] = pStat;
	
}

////////////////////////////////////////////////////////////////////////////////////
Statement *ApplicationManager::GetStatement(Point P) 
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL


	///Add your code here to search for a statement given a point P(x,y)	
	///WITHOUT breaking class responsibilities
	// Searches for a statement at the given point P and returns a pointer to it.
    // Returns NULL if no statement is found.
	// DONE

	for (int i = 0; i < StatCount; i++)
	{
			// Use the virtual function IsPointInside() defined in Statement.h 
			// to check if the point P is within the current statement's boundary.
			if (StatList[i]->IsPointInside(P))
			{
				// Found it! Return a pointer to the statement.
				return StatList[i];
			}
	}

		// No statement found at point P.
	return NULL;
	

}

void ApplicationManager::AddConnector1(Connector* pConn)
{
	if (ConnCount < MaxCount)
		ConnList[ConnCount++] = pConn;

}
Connector* ApplicationManager::GetConnector(Point P) const
{
	// Searches for a connector at the given point P and returns a pointer to it.
// Returns NULL if no connector is found.
	
		// Loop through all existing connectors.
	for (int i = 0;i < ConnCount; i++)
	{
			
			// to check if the point P lies near or on the connector's path.
			if (ConnList[i]->IsOnPath(P))
			{
				// Found it! Return a pointer to the connector.
				return ConnList[i];
			}
	}

		// No connector found at point P.
		return NULL;
	
}
////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement *ApplicationManager::GetSelectedStatement() const
{	return pSelectedStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{	pSelectedStat = pStat;	}

Connector* ApplicationManager::GetSelectedConnector() const  //Returns the selected connector
{ return pSelectedConn; }

void ApplicationManager::SetSelectedConnector(Connector* c) //Set the connector selected by the user
{ pSelectedConn = c; }
////////////////////////////////////////////////////////////////////////////////////
//Returns the Clipboard
Statement *ApplicationManager::GetClipboard() const
{	return pClipboard;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the Clipboard
void ApplicationManager::SetClipboard(Statement *pStat)
{	pClipboard = pStat;	}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//


//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();

	//Draw all statements
	for(int i=0; i<StatCount; i++)
		StatList[i]->Draw(pOut);
	
	//Draw all connections
	for(int i=0; i<ConnCount; i++)
		ConnList[i]->Draw(pOut);

}
void ApplicationManager::RemoveStatement(Statement* pStat) //to delete statement
{
	for (int i = 0; i < StatCount; i++)
	{
		if (StatList[i] == pStat)
		{
			delete StatList[i];

			// shift the array after delete
			for (int j = i; j < StatCount - 1; j++)
				StatList[j] = StatList[j + 1];
			StatCount--;
			pSelectedStat = nullptr;
		}
	}
}
void ApplicationManager::RemoveConnector(Connector* pConn)  //to delete connector
{
	for (int i = 0; i < ConnCount; i++)
	{
		if (ConnList[i] == pConn)
		{
			delete ConnList[i];

			// Shift the array after deleting
			for (int j = i; j < ConnCount - 1; j++)
				ConnList[j] = ConnList[j + 1];

			ConnCount--;
			pSelectedConn = nullptr;
			break;
		}
	}
}
void ApplicationManager::DeleteConnectorsOfstat(Statement* pStat)   //to delete connectors connected to statement
{
	for (int i = 0; i < ConnCount; i++)
	{
		if (ConnList[i]->getSrcStat() == pStat || ConnList[i]->getDstStat() == pStat)
		{
			RemoveConnector(ConnList[i]);
			i--; //to stay at same index to check the new element that moved here
		}
	}

}
int ApplicationManager::GetStatCount()
{
	return StatCount;
}
int ApplicationManager::GetConnCount()
{
	return ConnCount;
}
Statement** ApplicationManager::GetStatementList()
{
	return StatList;

}
Connector** ApplicationManager::GetConnectorList()
{
	return ConnList;
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////


//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
	
}
 
