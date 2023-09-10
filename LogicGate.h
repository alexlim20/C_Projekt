#ifndef LOGICGATE_H
#define LOGICGATE_H
#include "string.h"
#include "Point.h"
#include "TextBox.h"
#include "ColorBox.h"
#include "Wire.h"
class LogicGate: public TextBox
{
    mutable ColorBox Indicator;
    void updateIndicator();
protected:
    LogicGate* Input1,*Input2;
    Wire* InputWire1, *InputWire2;
public:
    LogicGate(const string& Operation, const Point& Position, LogicGate* Input1, LogicGate* Input2);
    LogicGate(const LogicGate& g);
    ~LogicGate();
    LogicGate& operator=(const LogicGate& rhs);
    void show();
    virtual bool genOutput() = 0 ;
    virtual void decorate(){Indicator.show();}
};

#endif // LOGICGATE_H
