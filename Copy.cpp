#include "Copy.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Statements\Statement.h"


Copy::Copy(ApplicationManager* pApp) : Action(pApp) {}

// ⚠️ تطبيق فارغ لـ ReadActionParameters()
void Copy::ReadActionParameters()
{
    // لا تحتاج عملية النسخ إلى قراءة أي معلمات من المستخدم
}

void Copy::Execute()
{
    // ... (الكود الحالي لـ Execute صحيح)
    Statement* pSel = pManager->GetSelectedStatement();
    if (pSel != nullptr)
    {
        Statement* pClone = pSel->Clone();  // يجب أن تكون دالة Clone مطبقة
        pManager->SetClipboard(pClone);     // تخزين النسخة في الـ Clipboard
        pManager->GetOutput()->PrintMessage("Statement copied to clipboard.");
    }
    else
        pManager->GetOutput()->PrintMessage("No statement selected to copy.");
}
