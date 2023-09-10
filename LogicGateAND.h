#ifndef LOGICGATEAND_H
#define LOGICGATEAND_H
#include "LogicGate.h"

class LogicGateAND:public LogicGate
{
public:
    LogicGateAND(const Point& Position, LogicGate* Input1, LogicGate* Input2)
    :LogicGate("AND", Position, Input1, Input2){}

    bool genOutput()
    {
        if(Input1 == nullptr && Input2 == nullptr)
        {
            return true;
        }else
        {
            if(Input1->genOutput()==1 && Input2->genOutput()==1)
            {
                return true;
            }else
            {
                return false;
            }
        }
    }

    void decorate()
    {
        LogicGate::decorate();
    }

};

#endif // LOGICGATEAND_H
