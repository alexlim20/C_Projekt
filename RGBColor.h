#ifndef RGBCOLOR_H
#define RGBCOLOR_H

class RGBColor
{
public:
    int R,G,B;
    RGBColor(int R, int G, int B):R(R), G(G), B(B){}

bool operator==(const RGBColor& p) const
{
    return (this->R==p.R)&&(this->G==p.G)&&(this->B==p.B);
}
};

#endif // RGBCOLOR_H
