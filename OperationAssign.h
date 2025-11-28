#ifndef OPERATION_ASSIGN_H
#define OPERATION_ASSIGN_H

#include "Statement.h"


class OperationAssign : public Statement
{
private:
    string LHS; //Left Handside of the assignment (name of a variable)
    string RHS1; //Right Handside (Variable or value)
    string RHS2; //Right Handside (Variable or value)
    char Operator;  // Arthmatic operator(+,-,*,/)

    Connector* pOutConn; //Operation Assignment Stat. has one Connector to next statement

    Point Inlet; //A point where connections enters this statement 
    //It's used as the (End) point of the (Input) connectors
    Point Outlet; //A point a connection leaves this statement
    //It's used as the (Start) point of the (Output) connector

    Point LeftCorner; //left corenr of the statement block.

    virtual void UpdateStatementText();

public:
    OperationAssign(Point Lcorner, string LeftHS = "", string RightHS1 = "", string RightHS2 = "", char op = '+');



    void setLHS(const string& L);
    void setRHS1(const string& R1);
    void setRHS2(const string& R2);
    void setOPerator(char op);

    virtual void Draw(Output* pOut) const;

};

#endif
