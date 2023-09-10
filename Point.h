#ifndef POINT_H
#define POINT_H
#include <ostream>
class Point
{
public:
    int X,Y;
    Point(int X, int Y):X(X),Y(Y){}

bool operator==(const Point& p) const
{
    return (this->X==p.X)&&(this->Y==p.Y);
}

bool operator!=(const Point& p) const
{
    return (this->Y!=p.Y)||(this->X!=p.X);
}

bool operator<(const Point& p) const
{
    return (this->Y<p.Y)&&(this->X<p.X);
}

bool operator>(const Point& p) const
{
    return (this->Y>p.Y)&&(this->X>p.X);
}

Point operator+(const Point& p) const
{
    Point temp(this->X + p.X, this->Y + p.Y);
    return temp;
}

Point operator-(const Point& p) const
{
    Point temp = Point(this->X - p.X, this->Y - p.Y);
    return temp;
}

Point& operator+=(const Point& p)
{
    this->X += p.X;
    this->Y += p.Y;
    return *this;
}

Point& operator-=(const Point& p)
{
    this->X -= p.X;
    this->Y -= p.Y;
    return *this;
}

Point operator*(int f)
{
    int newX = this->X * f;
    int newY = this->Y * f;
    Point temp = Point(newX, newY);
    return temp;
}

Point operator/(int f)
{
    int newX = this->X / f;
    int newY = this->Y / f;
    Point temp = Point(newX, newY);
    return temp;
}

Point& operator*=(int f)
{
    this->X *= f;
    this->Y *= f;
    return *this;
}

Point& operator/=(int f)
{
    this->X /= f;
    this->Y /= f;
    return *this;
}
};



#endif // POINT_H
