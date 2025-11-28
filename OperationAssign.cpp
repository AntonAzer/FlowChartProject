#include "OperationAssign.h"
#include <sstream> 


using namespace std;


OperationAssign::OperationAssign(Point Lcorner, string LeftHS,  string RightHS1, string RightHS2, char op)
{
    // Note: The LeftHS and RightHS should be validated inside (AddVariableAssign) action
    //       before passing it to the constructor of ValueAssign
    LHS = LeftHS;
    RHS1 = RightHS1;
    RHS2 = RightHS2;
    Operator = op;


    UpdateStatementText();

    LeftCorner = Lcorner;

    pOutConn = NULL; //No connectors yet

    Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
    Inlet.y = LeftCorner.y;

    Outlet.x = Inlet.x;
    Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}





void OperationAssign::setLHS(const string& L)
{
    LHS = L;
    UpdateStatementText();
}

void OperationAssign::setRHS1(const string& R1)
{
    RHS1 = R1;
    UpdateStatementText();
}
void OperationAssign::setRHS2(const string& R2)
{
    RHS2 = R2;
    UpdateStatementText();
}
void OperationAssign::setOPerator(char op)
{
    Operator = op;
    UpdateStatementText();
}




void OperationAssign::Draw(Output* pOut) const
{
    //Call Output::DrawAssign function to draw assignment statement  
    pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void OperationAssign::UpdateStatementText()
{
    //Build the statement text: Left handside then equals then right handside
    ostringstream T;
    T << LHS << " = " << RHS1 << " " << Operator << " " << RHS2;
    Text = T.str();
}
