#ifndef VARIABLE_ASSIGN_H
#define VARIABLE_ASSIGN_H

#include "Statement.h"


class VariableAssign : public Statement
{
private:
    string LHS; //Left Handside of the assignment (name of a variable)
    string RHS; //Right Handside (Variable)

    Connector* pOutConn; //Variable Assignment Stat. has one Connector to next statement
 
    Point Inlet; //A point where connections enters this statement 
    //It's used as the (End) point of the (Input) connectors
    Point Outlet; //A point a connection leaves this statement
    //It's used as the (Start) point of the (Output) connector

    Point LeftCorner; //left corenr of the statement block.

    virtual void UpdateStatementText();

public:
    VariableAssign(Point Lcorner, string LeftHS = "", string RightHS = "");

    

    void setLHS(const string& L);
    void setRHS(const string& R);

    virtual void Draw(Output* pOut) const;

};

#endif
