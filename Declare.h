#ifndef DECLARE_H
#define DECLARE_H

#include "Statement.h"


class Declare : public Statement
{
private:
   string var; 
    

    Connector* pOutConn;

    Point Inlet;
    Point Outlet;
    Point LeftCorner;

    virtual void UpdateStatementText();

public:
    Declare(Point Lcorner, string Variable = "");
    
    void setVariableName(const std::string& Variable);

    virtual void Draw(Output* pOut) const;

};

#endif
