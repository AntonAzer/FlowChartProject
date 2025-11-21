
#include "HelperFn.h"
#include "GUI\Input.h"
#include "GUI\Output.h"


//This is a test code to test the Input and Output classes

int main()
{

	Point P;

	//Create Input and Output objects to test
	Output* pOut = new Output();
	Input* pIn = pOut->CreateInput();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 0:	Testing the helper functions
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST0: Testing the helper functions");
	pIn->GetPointClicked(P);	//Wait for any click


	// DONE Tests
	// 1- Read a (string) from the user --> just call the already impemented Input::GetString(...) fn
		// 2- Pass this string to IsValue(...) helper function 
		// 3- Print a message indicating its output (whether it's a value or not)
		// 4- -- REPEAT the same previous 3 steps to test: IsVariable(...) helper function
		// 5- -- REPEAT the same first 3 steps to test: ValueORVariable(...) helper function


	// 1) Test IsValue

	pOut->PrintMessage("Enter a string to test IsValue:");
	string s1 = pIn->GetString(pOut);

	if (IsValue(s1))	pOut->PrintMessage("IsValue: TRUE");
	else   pOut->PrintMessage("IsValue: FALSE");

	Sleep(500); // البرنامج يفريز نص


	// 2) Test IsVariable

	pOut->PrintMessage("Enter a string to test IsVariable:");
	string s2 = pIn->GetString(pOut);

	if (IsVariable(s2))
		pOut->PrintMessage("IsVariable: TRUE");
	else
		pOut->PrintMessage("IsVariable: FALSE");

	Sleep(500);


	// 3) Test ValueOrVariable

	pOut->PrintMessage("Enter a string to test ValueOrVariable:");
	string s3 = pIn->GetString(pOut);

	OpType op = ValueOrVariable(s3);

	if (op == VALUE_OP)
	{
		pOut->PrintMessage("ValueOrVariable: VALUE_OP");
	}
	else if (op == VARIABLE_OP) // I accesed VARIABLE_OP because it is an enum cons
	{
		pOut->PrintMessage("ValueOrVariable: VARIABLE_OP");
	}
	else
	{
		pOut->PrintMessage("ValueOrVariable: INVALID_OP");
	}


	Sleep(500);



	//Starting the input and output classes test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(P);	//Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	Create The FULL Tool bar, the drawing area, the output bar and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(P);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	Drawing all the Statements with all possible states:
	//			Normal, highlighted, empty, filled with code
	//			Also drawing connectors
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any statement in any status, Click anywhere to continue");
	pIn->GetPointClicked(P);	//Wait for any click

	/// 2.1- Assignment statement test
	//Drawing assignment statements in all posible states

	pOut->PrintMessage("Drawing Simple Assignment statements in ALL STATES, Click to continue");

	//Drawing (normal) (empty) assignment statement --> STATE 1
	P.x = 100;	P.y = 100;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " = ");

	//Drawing (highlighted) (empty) assignment statement --> STATE 2
	P.x = 300;	P.y = 100;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " = ", true);

	//Drawing a resized empty assignment statement
	P.x = 100;	P.y = 200;
	pOut->DrawAssign(P, 80, UI.ASSGN_HI, " = ");

	//Drawing edited (normal) (non-empty) assignment statement --> STATE 3
	P.x = 100;	P.y = 300;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = 3000");

	//Drawing (highlighted) (non-empty) assignment statement --> STATE 4
	P.x = 300;	P.y = 300;
	pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = 3000", true);

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	///2.2- Variable assignment & single operator assignment
	pOut->PrintMessage("Drawing other Assignment statements in ALL STATES, Click to continue");

	//Note: for other type of assignment, you can use the same draw assignment function but passing a different text

	////////////
	//DONE: Add code to draw other types of assignment statements (Variable and Operator) here in ALL STATES
	//just 2 line below
	pOut->DrawAssign(P, 120, 50, "x = 5", true);
	pOut->DrawAssign(P, 120, 100, "y = 6", true);


	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.3- Conditional statement test
	//Drawing Conditional statements in all posible states
	pOut->PrintMessage("Drawing Conditional Statement in ALL STATES, Click to continue");

	////////////
	//DONE: Add code to draw different (Conditional) statements here in ALL STATES
	////////////
	pOut->DrawCond(P, 90, 70, "conditionText", false);

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.4- Read statement test
	//Drawing Read statements in all posible states
	pOut->PrintMessage("Drawing Read Statement in ALL STATES, Click to continue");

	////////////
	//DONE: Add code to draw different (Read) statements here in ALL STATES
	////////////
	pOut->DrawReadandWrite(20, 90, 100, "ANY");


	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.5- Write statement test
	//Drawing Write statements in all posible states
	pOut->PrintMessage("Drawing Write Statement in ALL STATES, Click to continue");

	////////////
	//DONE: Add code to draw different (Write) statements here in ALL STATES
	////////////
	pOut->DrawReadandWrite(100, 200, 120, "x = 5");
	// DrawReadandWrite(Point Left, int width, int height, string Text, bool Selected = false); شكل الداله   

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();


	/// 2.6- Start & End statements test
	//Drawing Start & End statements in all posible states
	pOut->PrintMessage("Drawing Start & End Statements in ALL STATES, Click to continue");

	////////////
	//DONE: Add code to draw different (Start & End) statements here  in ALL STATES
	////////////
	pOut->DrawStartorEnd(P, 80, 120, "Start", false);

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();


	/// 2.7- Connector test
	//Drawing Connector in all posible states
	pOut->PrintMessage("Drawing Connector in Normal and Highlighted STATES, Click to continue");

	////////////
	//DONE: Add code to draw different (Connectors) here:  Normal and Highlighted
	////////////
	pOut->DrawConnector(P, 100, false);



	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.8- Draw String TEST
	//Drawing a String in a specific location
	pOut->PrintMessage("Drawing A String, Click to continue");

	//Note: the function of this drawing is already implemented in Output class , you only need to call it

	////////////
	//DONE: Add code to: 
	// 1- Get a String from the user --> using the already-implemented Input::GetString(...) fn
	// 2- Draw that string in location (400, 200) --> using the already-implemented Output::DrawString(...) fn

	string userText = pIn->GetString(pOut);
	pOut->DrawString(400, 200, userText);


	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: Read strings and a value from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(P);	//Wait for any click

	pOut->PrintMessage("Testing Input ability to read strings, values, variables and operators");

	////////////
	//TODO: Add code here to 
	// 1- Read a (double value) from the user and print it
	// 2- Read a (variable name) from the user and print it
	// 3- Read an (arithmatic operator) from the user and print it
	// 4- Read a (comparison operator) from the user and print it
	////////////
	double value = pIn->GetValue(pOut);   // get value and printing it
	pOut->PrintMessage("Value entered: " + to_string(value));
	// Tricky one to put double with words

	pIn->GetPointClicked(P);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	////////////
	//TODO:  You must add a case for EACH action in the following (switch case)
	////////////

	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case ADD_VALUE_ASSIGN:
			pOut->PrintMessage("Action: add value assignment statement , Click anywhere");
			break;

		case ADD_CONDITION:
			pOut->PrintMessage("Action: add conditional statement , Click anywhere");
			break;

		case ADD_CONNECTOR:
			pOut->PrintMessage("Action: add a connector , Click anywhere");
			break;

		case SELECT:
			pOut->PrintMessage("Action: select action, Click anywhere");
			break;

		case STATUS:
			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
			break;

		case (DSN_TOOL):
			pOut->PrintMessage("Action: a click on the Design Tool Bar, Click anywhere");
			break;

		case SWITCH_SIM_MODE:
			pOut->PrintMessage("Action: Switch to Simulation Mode, creating simualtion tool bar");
			pOut->CreateSimulationToolBar(); // THIS TESTS Output::CreateSimulationToolBar() function //////
			break;

		case SWITCH_DSN_MODE:
			pOut->PrintMessage("Action: Switch to Design Mode, creating Design tool bar");
			pOut->CreateDesignToolBar();
			break;


		case EXIT:
			break;

			// FROM HERE I CHECK THE REST 
		case (ADD_START):
			pOut->PrintMessage("Action: add start statement, Click anywhere");
			break;

		case (ADD_END):
			pOut->PrintMessage("Action: add end statement, Click anywhere");
			break;

		case (ADD_DECLARE_VARIABLE):
			pOut->PrintMessage("Action: add declare variable statement, Click anywhere");
			break;

		case (ADD_VAR_ASSIGN):
			pOut->PrintMessage("Action: add variable assignment statement, Click anywhere");
			break;

		case (ADD_OPER_ASSIGN):
			pOut->PrintMessage("Action: add operator assignment statement, Click anywhere");
			break;

		case (ADD_READ):
			pOut->PrintMessage("Action: add read statement, Click anywhere");
			break;

		case (ADD_WRITE):
			pOut->PrintMessage("Action: add write statement, Click anywhere");
			break;

		case EDIT_STAT:
			pOut->PrintMessage("Action: edit a statement, Click anywhere");
			break;

		case DEL:
			pOut->PrintMessage("Action: delete a figure, Click anywhere");
			break;

		case COPY:
			pOut->PrintMessage("Action: copy a figure, Click anywhere");
			break;

		case CUT:
			pOut->PrintMessage("Action: cut a figure, Click anywhere");
			break;

		case PASTE:
			pOut->PrintMessage("Action: paste a figure, Click anywhere");
			break;

		case SAVE:
			pOut->PrintMessage("Action: save the graph");
			break;

		case LOAD:
			pOut->PrintMessage("Action: load a graph");
			break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: click on drawing area, Click anywhere");
			break;

		case OUTPUT_AREA:
			pOut->PrintMessage("Action: click on output area, Click anywhere");
			break;

		default:
			pOut->PrintMessage("Unknown Action");
			break;
			// It was so boring ,GOOD BYE

		}
	}
		while (ActType != EXIT);
	

		/// Exiting
		pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
		pIn->GetPointClicked(P);


		delete pIn;
		delete pOut;
		return 0;
	}



