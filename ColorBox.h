#include "Point.h"
#include "RGBColor.h"

#ifndef COLORBOX_H
#define COLORBOX_H

class ColorBox
{
protected:
    Point Pos;
    Point Size;
    RGBColor Color;
public:
    ColorBox(const Point& Pos, const Point& Size, const RGBColor& Color);
    bool contains(const Point f) const;
    Point getPosition() const;
    Point getSize() const;
    RGBColor getColor() const;
    void setPosition(const Point p);
    void setSize(const Point s);
    void setColor(const RGBColor c);
    void show();
};

#endif // COLORBOX_H
