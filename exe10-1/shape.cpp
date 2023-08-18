#include <iostream>
#include "shape.h"

using namespace std;

// Shape
Shape::Shape()
{
  color = 0;
}

Shape::Shape(int color)
{
  this->color = color;
}

double Shape::getColor() const
{
  return color;
}

// Point2D

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

void Point2D::set(int x, int y)
{
  this->x = x;
  this->y = y;
}

int Point2D::getX() const
{
  return x;
}

int Point2D::getY() const
{
  return y;
}

// Circle
Circle::Circle(int color, Point2D center, double radius) : Shape(color)
{
  this->center = center;
  this->radius = radius;
}

double Circle::area() const
{
  return 3.14 * radius * radius;
}

void Circle::draw() const
{
  cout << "Center: (" << center.getX() << ", " << center.getY() << ")" << endl;
  cout << "Radius: " << radius << endl;
}

// Triangle
Triangle::Triangle(int color, Point2D *vertices) : Shape(color)
{
  this->vertices = vertices;
}

Triangle::~Triangle()
{
  delete [] vertices;
}

int Triangle::area() const
{
  return (vertices[1].getX() - vertices[0].getX()) * (vertices[2].getY() - vertices[0].getY()) / 2;
}

void Triangle::draw() const
{
  cout << "Vertices: (" << vertices[0].getX() << ", " << vertices[0].getY() << "), (" << vertices[1].getX() << ", " << vertices[1].getY() << "), (" << vertices[2].getX() << ", " << vertices[2].getY() << ")" << endl;
}

// Circle_in_Triangle
Circle_in_Triangle::Circle_in_Triangle(int color, Point2D center, double radius, Point2D *vertices) : Shape(color), Circle(color, center, radius), Triangle(color, vertices)
{
}

double Circle_in_Triangle::area() const
{
  return Triangle::area() - Circle::area();
}

void Circle_in_Triangle::draw() const
{
  cout << "Circle’s color: " << getColor() << endl;
  cout << "Triangle’s color: " << getColor() << endl;
  Circle::draw();
  Triangle::draw();
}

