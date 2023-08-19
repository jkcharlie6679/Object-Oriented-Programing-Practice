#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
private:
  int *x;
  int *y;
public:
  Point2D(int , int );
  void display() const;
  void setX(int);
  void setY(int);
  int getX() const;
  int getY() const;
};

#endif
