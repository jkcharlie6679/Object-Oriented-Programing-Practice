#ifndef POINT4D_H
#define POINT4D_H
#include "Point2D.h"

class Point4D : public Point2D
{
private:
  int *z;
  int *t;
public:
  Point4D(int ,int ,int ,int );
  void display() const;
  const Point4D& operator=(const Point2D&);
};

#endif

