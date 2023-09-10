#include "TextBox.h"
#include "ColorBox.h"
#include "WinAdapt.h"

TextBox::TextBox(Point pos, Point size, const string& Text)
:ColorBox(pos, size, RGBColor(255,255,255)), Text(Text){}

string TextBox::getText() const
{
    return Text;
}

void TextBox::setText(const string& text)
{
    Text = text;
}

void TextBox::show()
{
    ColorBox::show();
    ::Text(Pos.X+5, Pos.Y+5, Text.c_str());
}
