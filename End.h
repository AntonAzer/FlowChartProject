#ifndef END_H
#define END_H

#include "Statement.h"

class End : public Statement
{
private:
    Point Center;
    int width, height;

    virtual void UpdateStatementText();

public:
    End(Point C);

    virtual void Draw(Output* pOut) const;
};

#endif