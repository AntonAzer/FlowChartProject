
#include "End.h"
#include "..\GUI\UI_Info.h"

// Constructor
End::End(Point C)
{
    Center = C;
    width = UI.ASSGN_WDTH;
    height = UI.ASSGN_HI;
    Text = "End";
    Selected = false;
}

void End::UpdateStatementText()
{
    // End text is fixed
    Text = "End";
}

void End::Draw(Output* pOut) const
{
    pOut->DrawEnd(Center, width, height, Text, Selected);
}