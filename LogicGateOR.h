#ifndef LOGICGATEOR_H
#define LOGICGATEOR_H
#include "LogicGate.h"

class LogicGateOR : public LogicGate
{
public:
    LogicGateOR(const Point& Position, LogicGate* Input1, LogicGate* Input2)
    :LogicGate("OR", Position, Input1, Input2){}

    bool genOutput()
    {
        if(Input1==nullptr && Input2==nullptr)
        {
            return true;
        }else
        {
            if(Input1->genOutput()==0 && Input2->genOutput()==0)
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
        LogicGate::decorate();
    }
};

#endif // LOGICGATEOR_H
