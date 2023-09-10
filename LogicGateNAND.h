#ifndef LOGICGATENAND_H
#define LOGICGATENAND_H
#include "LogicGate.h"

class LogicGateNAND : public LogicGate
{
public:
    LogicGateNAND(const Point& Position, LogicGate* Input1, LogicGate* Input2)
    :LogicGate("NAND", Position, Input1, Input2){}

    bool genOutput()
    {
        if(Input1==nullptr && Input2==nullptr)
        {
            return true;
        }else
        {
            if(Input1->genOutput()==1 && Input2->genOutput()==1)
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
        Elli(Pos.X+Size.X, Pos.Y+((Size.Y)/2)-5, Pos.X+Size.X+10, Pos.Y+((Size.Y)/2)+5);
        LogicGate::decorate();
    }
};

#endif // LOGICGATENAND_H
