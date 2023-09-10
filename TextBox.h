#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <string>
#include "ColorBox.h"
using namespace std;

class TextBox : public ColorBox
{
    string Text;
public:
    TextBox(Point pos, Point size, const string& Text);
    string getText() const;
    void setText(const string& text);
    void show();
};

#endif // TEXTBOX_H
