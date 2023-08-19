#include <iostream>
#include "Point2D.h"

using namespace std;

Point2D::Point2D(int n1, int n2)
{
  x = new int;
  y = new int;
  *x = n1;
  *y = n2;
}

void Point2D::display() const
{
  cout << "(" << *x << ", " << *y << ")";
}

void Point2D::setX(int n)
{
  *x = n;
}

void Point2D::setY(int n)
{
  *y = n;
}

int Point2D::getX() const
{
  return *x;
}

int Point2D::getY() const
{
  return *y;
}

