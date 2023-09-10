#include "Wire.h"
#include "WinAdapt.h"

void Wire::show()
{
    if(Start.Y==End.Y || Start.X==End.X)
    {
        Line(Start.X, Start.Y, End.X, End.Y);
    }else
    {
        int midX = (Start.X+End.X)/2;
        int deltaY = Start.Y-End.Y;
        Line(Start.X,Start.Y, midX, Start.Y);
        Line(midX, Start.Y, midX, End.Y);
        Line(midX, End.Y, End.X, End.Y);
    }
}
