#ifndef LOGICGATEXOR_H
#define LOGICGATEXOR_H
#include "LogicGate.h"

class LogicGateXOR : public LogicGate
{
public:
    LogicGateXOR(const Point& Position, LogicGate* Input1, LogicGate* Input2)
    :LogicGate("XOR", Position, Input1, Input2){}

    bool genOutput()
    {
        if(Input1==nullptr && Input2==nullptr)
        {
            return true;
        }else
        {
            if(Input1->genOutput()==Input2->genOutput())
            {
                return false;
            }else
            {
                return true;
            }
        }
    }

    void decorate()
    {
        FillCol(0,0,0);
        Rect(Pos.X+Size.X, Pos.Y, Pos.X+Size.X+5, Pos.Y+Size.Y);
        LogicGate::decorate();
    }
};

#endif // LOGICGATEXOR_H
