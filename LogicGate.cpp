#include "LogicGate.h"

LogicGate::LogicGate(const string& Operation, const Point& Position, LogicGate* Input1, LogicGate* Input2)
:TextBox(Position, Point(80,50), Operation), Input1(Input1), Input2(Input2), Indicator(Pos+Size-Point(15,15),Point(10,10),RGBColor(255,255,255))
{
    if(Input1!=nullptr && Input2!=nullptr)
    {
        Point Point1Start = Point(Input1->Size.X+Input1->Pos.X, Input1->Pos.Y+(Input1->Size.Y)/2);
        Point Point1End = Point(this->Pos.X, this->Pos.Y+(this->Size.Y)/4);
        Wire* newWire1 = new Wire(Point1Start, Point1End);
        Point Point2Start = Point(Input2->Size.X+Input2->Pos.X, Input2->Pos.Y+(Input2->Size.Y)/2);
        Point Point2End = Point(this->Pos.X, this->Pos.Y+3*(this->Size.Y)/4);
        Wire* newWire2 = new Wire(Point2Start, Point2End);
        InputWire1 = newWire1;
        InputWire2 = newWire2;
    }else
    {
        InputWire1 = nullptr;
        InputWire2 = nullptr;
    }
}

LogicGate::LogicGate(const LogicGate& g)
:TextBox(g.Pos, g.Size, g.getText()), Input1(g.Input1), Input2(g.Input2), InputWire1(g.InputWire1), InputWire2(g.InputWire2), Indicator(g.Indicator)
{}

LogicGate::~LogicGate()
{
    if(Input1!=nullptr && Input2!=nullptr)
    {
        delete InputWire1;
        delete InputWire2;
    }
}

LogicGate& LogicGate::operator=(const LogicGate& rhs)
{
    Pos = rhs.Pos;
    Size = rhs.Size;
    Color = rhs.Color;
    Input1 = rhs.Input1;
    Input2 = rhs.Input2;
    InputWire1 = rhs.InputWire1;
    InputWire2 = rhs.InputWire2;
}

void LogicGate::show()
{
    TextBox::show();
    updateIndicator();
    if(Input1!=nullptr && Input2!=nullptr)
    {
        Input1->show();
        Input2->show();
        InputWire1->show();
        InputWire2->show();
    }
    decorate();
}

void LogicGate::updateIndicator()
{
    if(genOutput()==1)
    {
        Indicator.setColor(RGBColor(0,255,0));
    }else
    {
        Indicator.setColor(RGBColor(255,0,0));
    }
}
