#include "Read.h"
#include <sstream> 


using namespace std;


Read::Read(Point Lcorner, string variable)
{
 
    var = variable;

    UpdateStatementText();

    LeftCorner = Lcorner;

    pOutConn = NULL; //No connectors yet

    Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
    Inlet.y = LeftCorner.y;

    Outlet.x = Inlet.x;
    Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}



void Read::setVar(const string& Variable)
{
    var = Variable;
    UpdateStatementText();
}


void Read::Draw(Output* pOut) const
{
    //Call Output::DrawAssign function to draw assignment statement  
    pOut->DrawReadStat(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void Read::UpdateStatementText()
{
    //Build the statement text: Left handside then equals then right handside
    ostringstream T;
    T << "Read  " << var;
    Text = T.str();
}
