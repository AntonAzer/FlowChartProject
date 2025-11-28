#ifndef ADD_CONDITION_H
#define ADD_CONDITION_H 

#include "ApplicationManager.h"
#include "Actions/Action.h"
#include "Condition.h"



// Add Condition Action
class AddCondition : public Action
{
private:
	Point Position; // placement (top vertex)
	string LHS, Comp, RHS;

public:
	AddCondition(ApplicationManager *pAppManager);

	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif