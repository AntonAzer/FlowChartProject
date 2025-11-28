#include "Start.h"
#include "..\GUI\UI_Info.h"

Start::Start(Point C)
{
    Center = C;
    width = UI.ASSGN_WDTH; // reuse default sizes
    height = UI.ASSGN_HI;
    Text = "Start";
    Selected = false;
}

void Start::UpdateStatementText()
{
    // Start text is fixed
    Text = "Start";
}

void Start::Draw(Output* pOut) const
{
    // Output::DrawStart expects center, width, height, text, selected
    pOut->DrawStart(Center, width, height, Text, Selected);
}