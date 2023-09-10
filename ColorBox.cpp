#include "ColorBox.h"
#include "WinAdapt.h"

ColorBox::ColorBox(const Point& Pos, const Point& Size, const RGBColor& Color)
:Pos(Pos), Size(Size), Color(Color){}

bool ColorBox::contains(const Point f) const
{
    return ((f.X>=Pos.X) && (f.X<=Pos.X+Size.X))&&((f.Y>=Pos.Y) && (f.X<=Pos.X+Size.Y));
}

Point ColorBox::getPosition() const
{
    return Pos;
}

Point ColorBox::getSize() const
{
    return Size;
}

RGBColor ColorBox::getColor() const
{
    return Color;
}

void ColorBox::setPosition(const Point p)
{
    Pos = p;
}

void ColorBox::setSize(const Point s)
{
    Size = s;
}

void ColorBox::setColor(const RGBColor c)
{
    Color = c;
}

void ColorBox::show()
{
    FillCol(Color.R, Color.G, Color.B);
    Rect(Pos.X, Pos.Y, Pos.X+Size.X, Pos.Y+Size.Y);
}
