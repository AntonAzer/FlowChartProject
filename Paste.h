#ifndef PASTE_H
#define PASTE_H

#include "Action.h"

// Action to paste a statement from the clipboard
class Paste : public Action
{
private:
    Point Position; // موقع اللصق
public:
    Paste(ApplicationManager* pApp);

    virtual void ReadActionParameters();
    virtual void Execute();
};

#endif