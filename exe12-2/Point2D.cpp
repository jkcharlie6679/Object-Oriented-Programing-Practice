#include <iostream>
#include "Point2D.h"

using namespace std;

Point2D::Point2D()
{
  x = 0;
  y = 0;
}

Point2D::Point2D(int x, int y)
{
  this->x = x;
  this->y = y;
}

void Point2D::setX(int x)
{
  this->x = x;
}

void Point2D::setY(int y)
{
  this->y = y;
}

Point2D &Point2D::operator=(const int &val)
{
  x = val;
  y = val;
  return *this;
}

Point2D &Point2D::operator+=(const Point2D &p)
{
  x += p.x;
  y += p.y;
  return *this;
}

Point2D Point2D::operator*(const Point2D &p)
{
  Point2D tmp;
  tmp.x = x * p.x;
  tmp.y = y * p.y;
  return tmp;
}

ostream &operator<<(ostream &out, const Point2D &p)
{
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

