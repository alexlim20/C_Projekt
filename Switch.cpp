#include "Switch.h"
#include <iostream>
#include <stdio.h>

Switch::Switch():ColorBox(Point(0,0), Point(0,0), RGBColor(169,169,169))
{
    OnButton = nullptr;
    OffButton = nullptr;
    Indicator = nullptr;
    State = 0;
}

Switch::Switch(const Switch& s):ColorBox(s.getPosition(), s.getSize(), RGBColor(169,169,169))
{
    OnButton = new TextBox(s.OnButton->getPosition(),s.OnButton->getSize(), s.OnButton->getText());
    OffButton = new TextBox(s.OffButton->getPosition(), s.OffButton->getSize(), s.OffButton->getText());
    Indicator = new ColorBox(s.Indicator->getPosition(), s.Indicator->getSize(), s.Indicator->getColor());
    State = s.getState();
    std::cout<<"ctor"<<endl;
}

Switch::Switch(const Point& pos, const string& OnButtonLabel, const string& OffButtonLabel)
:ColorBox(pos, Point(100,40), RGBColor(169,169,169))
{
    State=0;
    Point s = Point((Size.X-12)/3, Size.Y-6);
    OnButton = new TextBox(pos+Point(3,3), s, OnButtonLabel);
    OffButton = new TextBox(pos+Point(s.X+6,3), s, OffButtonLabel);
    Indicator = new ColorBox(pos+Point(2*(s.X)+9,3), s, RGBColor(105,105,105));
}

Switch::~Switch()
{
    delete OnButton;
    delete OffButton;
    delete Indicator;
}

void Switch::onMouse(const Point& p)
{
    if(p>OnButton->getPosition() && p<(OnButton->getPosition()+OnButton->getSize()))
    {
        State = 1;
        setState(State);
    }else if(p>OffButton->getPosition() && p<(OffButton->getPosition()+OffButton->getSize()))
    {
        State = 0;
        setState(State);
    }
}

void Switch::setPosition(const Point& p)
{
    Pos = p;
    OnButton->setPosition(Pos+Point(3,3));
    OffButton->setPosition(Pos+Point(206/3,3));
    Indicator->setPosition(Pos+Point(403/3,3));
}

bool Switch::getState() const
{
    return State;
}

void Switch::setState(const bool State)
{
    if(State)
    {
        Indicator->setColor(RGBColor(0,255,0));
    }else
    {
        Indicator->setColor(RGBColor(255,0,0));
    }
}

Switch& Switch::operator=(const Switch& s)
{
    if(this != &s)
    {
        this->~Switch();
        Pos = s.Pos;
        Size=s.Size;
        Color=s.Color;
        State = s.State;
        OnButton = new TextBox(s.OnButton->getPosition(),s.OnButton->getSize(), s.OnButton->getText());
        OffButton = new TextBox(s.OffButton->getPosition(), s.OffButton->getSize(), s.OffButton->getText());
        Indicator = new ColorBox(s.Indicator->getPosition(), s.Indicator->getSize(), s.Indicator->getColor());
        std::cout<<"=operator"<<endl;
        return *this;
    }
}

void Switch::show()
{
    ColorBox::show();
    OnButton->show();
    OffButton->show();
    Indicator->show();
}
