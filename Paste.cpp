#include "Paste.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Statements\Statement.h"
Paste::Paste(ApplicationManager* pApp) : Action(pApp) {}

void Paste::ReadActionParameters()
{
    Input* pIn = pManager->GetInput();
    Output* pOut = pManager->GetOutput();

    pOut->PrintMessage("Paste: Click where you want to place the statement.");
    pIn->GetPointClicked(Position); // قراءة موقع اللصق
    pOut->ClearStatusBar();
}

void Paste::Execute()
{
    ReadActionParameters(); 

    Statement* pCloned = pManager->GetClipboard();
    if (pCloned != nullptr)
    {
        Statement* pNew = pCloned->Clone();

        // تحديث مركز الـ Statement الجديد إلى موقع النقر
        pNew->SetCenter(Position);

        // إعادة تعيين الموصلات (Connectors)
        pNew->setOutConnector(nullptr);
        // قد تحتاج أيضًا إلى إعادة تعيين خاصية الـ ID وغيرها

        pManager->AddStatement(pNew);
        pManager->GetOutput()->PrintMessage("Statement pasted successfully.");
    }
    else
        pManager->GetOutput()->PrintMessage("Clipboard is empty or contains invalid data.");
}