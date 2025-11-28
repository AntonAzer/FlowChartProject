#ifndef START_H
#define START_H

#include "Statement.h"

class Start : public Statement
{
private:
    Point Center;
    int width, height;

    // Ensure Statement's pure virtual is implemented
    virtual void UpdateStatementText();

public:
    Start(Point C);

    // Draw the start statement (ellipse with "Start")
    virtual void Draw(Output* pOut) const;
};

#endif