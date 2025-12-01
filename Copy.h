#ifndef COPY_H
#define COPY_H

#include "Action.h"

// Action to copy the selected statement
class Copy : public Action
{
public:
    Copy(ApplicationManager* pApp);

    // Reads parameters required for action to execute
    // Copy doesn't need to read parameters, but must implement the pure virtual function
    virtual void ReadActionParameters();

    // Execute action
    virtual void Execute();
};

#endif