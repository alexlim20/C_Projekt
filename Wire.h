#ifndef WIRE_H
#define WIRE_H
#include "Point.h"
class Wire
{
    Point Start, End;
public:
    Wire(const Point& Start, const Point& End)
    :Start(Start), End(End){}

    Wire(const Wire& other)
    :Start(other.Start), End(other.End){}

    const Point& getStart() const
    {
        return Start;
    }

    const Point& getEnd() const
    {
        return End;
    }

    void setStart(const Point& Start)
    {
        this->Start = Start;
    }

    void setEnd(const Point& End)
    {
        this->End = End;
    }

    void show();
};

#endif // WIRE_H
