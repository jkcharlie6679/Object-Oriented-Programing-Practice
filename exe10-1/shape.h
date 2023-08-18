#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
protected:
  int color;
public:
  Shape();
  Shape(int);
  virtual double getColor() const;
};

class Point2D
{
protected:
  int x;
  int y;
public:
  Point2D();
  Point2D(int, int);
  void set(int, int);
  int getX() const;
  int getY() const;
};

class Circle : virtual public Shape
{
protected:
  Point2D center;
  double radius;
public:
  Circle(int, Point2D, double);
  double area() const;
  void draw() const;
};

class Triangle : virtual public Shape
{
protected:
  Point2D *vertices;
public:
  Triangle(int, Point2D *);
  ~Triangle();
  int area() const;
  void draw() const;
};

class Circle_in_Triangle: public Circle, public Triangle
{
public:
  Circle_in_Triangle(int, Point2D , double , Point2D *);
  double area() const;
  void draw() const;
 };

#endif

