#ifndef READ_H
#define READ_H

#include "Statement.h"


class Read : public Statement
{
private:
	string var;

	Connector* pOutConn;	//Read Stat. has one Connector to next statement

	Point Inlet;	//A point where connections enters this statement 
	//It's used as the (End) point of the (Input) connectors
	Point Outlet;	//A point a connection leaves this statement
	//It's used as the (Start) point of the (Output) connector

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	Read(Point Lcorner, string variable="");

	void setVar(const string& Variable);
	
	virtual void Draw(Output* pOut) const;

};

#endif
