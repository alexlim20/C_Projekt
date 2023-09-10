#ifndef SWITCH_H
#define SWITCH_H
#include "ColorBox.h"
#include "TextBox.h"

class Switch : public ColorBox
{
    int State;
    TextBox* OnButton;
    TextBox* OffButton;
    ColorBox* Indicator;
public:
    Switch();
    Switch(const Switch& s);
    Switch(const Point& pos, const string& OnButtonLabel, const string& OffButtonLabel);
    virtual ~Switch();
    void onMouse(const Point& p);
    void setPosition(const Point& p);
    bool getState() const;
    void setState(bool State);
    Switch& operator=(const Switch& s);
    void show();
};

#endif // SWITCH_H
