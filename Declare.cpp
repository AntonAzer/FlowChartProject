#include "Declare.h"
#include <sstream>

using namespace std;


Declare::Declare(Point Lcorner, string Variable) 
{
    var = Variable;

    UpdateStatementText();

    LeftCorner = Lcorner;
    pOutConn = NULL;

  
    Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
    Inlet.y = LeftCorner.y;

    Outlet.x = Inlet.x;
    Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}



void Declare::setVariableName(const string& Variable)
{
    var = Variable;
    UpdateStatementText();
}


void Declare::Draw(Output* pOut) const
{
   
    pOut->DrawAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}


void Declare::UpdateStatementText()
{
    ostringstream T;
    T << "double  " <<  var;
    Text = T.str();
}
