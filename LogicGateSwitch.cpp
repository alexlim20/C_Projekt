#include "LogicGateSwitch.h"

LogicGateSwitch::LogicGateSwitch(const string& Label, const Point& Position)
:LogicGate(Label, Position, nullptr, nullptr), Schaltelement(new Switch(Point(Position.X+70, Position.Y+3),"On", "Off"))
{
    setSize(Point(Schaltelement->getSize().X+73,Schaltelement->getSize().Y+6));
}

LogicGateSwitch::LogicGateSwitch(const LogicGateSwitch& g)
:LogicGate(g.getText(), g.Pos, g.Input1, g.Input2), Schaltelement(new Switch(g.Schaltelement->getPosition(), "On", "Off"))
{}

LogicGateSwitch::~LogicGateSwitch()
{
    if(Schaltelement!=nullptr)
    {
        delete Schaltelement;
    }
}

bool LogicGateSwitch::genOutput()
{
    return Schaltelement->getState();
}

void LogicGateSwitch::onMouse(const Point& where)
{
    Schaltelement->onMouse(where);
}

void LogicGateSwitch::decorate()
{
    Schaltelement->show();
}

LogicGateSwitch& LogicGateSwitch::operator=(const LogicGateSwitch& rhs)
{
    *this = LogicGateSwitch(rhs);
}
