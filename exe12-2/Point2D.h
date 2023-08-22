#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

using namespace std;

class Point2D
{
private:
  int x;
  int y;
public:
  Point2D();
  Point2D(int, int);
  void setX(int);
  void setY(int);
  Point2D &operator=(const int &);
  Point2D &operator+=(const Point2D &);
  Point2D operator*(const Point2D &);
  friend ostream &operator<<(ostream &, const Point2D &);
};

ostream &operator<<(ostream &, const Point2D &);

#endif

