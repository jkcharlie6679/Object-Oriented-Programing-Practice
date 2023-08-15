#include <iostream>
#include "Point4D.h"

using namespace std;

Point4D::Point4D(int n1, int n2, int n3, int n4) : Point2D(n1, n2)
{
  z = new int;
  t = new int;
  *z = n3;
  *t = n4;
}

void Point4D::display() const
{
  cout << "(" << getX() << ", " << getY() << ", " << *z << ", " << *t << ")";
}

const Point4D& Point4D::operator=(const Point2D& pt)
{
  setX(pt.getX());
  setY(pt.getY());
  *z = 0;
  *t = 0;
  return *this;
}

