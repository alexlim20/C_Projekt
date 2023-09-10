#ifndef LOGICGATESWITCH_H
#define LOGICGATESWITCH_H
#include "LogicGate.h"
#include "Switch.h"

class LogicGateSwitch : public LogicGate
{
protected:
    Switch* Schaltelement;
public:
    LogicGateSwitch(const string& Label, const Point& Position);
    LogicGateSwitch(const LogicGateSwitch& g);
    ~LogicGateSwitch();
    bool genOutput();
    void onMouse(const Point& where);
    void decorate();
    LogicGateSwitch& operator=(const LogicGateSwitch& rhs);
};

#endif // LOGICGATESWITCH_H
