#include <iostream>

using std::cout; using std::endl;

class Point2D
{
private:
  int *x;
  int *y;
public:
  Point2D()
  {
    x = new int (0);
    y = new int (0);
  }
  Point2D (int a, int b)
  {
    x = new int (a);
    y=new int (b); 
  }
  Point2D (const Point2D& pt)
  {
    x = new int (*pt.x);
    y = new int (*pt.y);
  }
  virtual ~Point2D ()
  {
    if (x != NULL) 
      delete x;
    if (y != NULL) 
      delete y;
  }
  void setPoint2D (int a, int b)
  {
    *x = a;
    *y = b;
  }
  int getX () const
  {
    return *x;
  }
  int getY () const
  {
    return *y;
  }
  virtual void display () const
  {
    cout << *x << "," << *y;
  }
};

class Shape
{
public:
  virtual double area ()
  {
    return 0;
  };
  virtual ~Shape(){}
};

class Circle: public Shape
{
private:
  Point2D center;
  double radius;
public:
  Circle(Point2D pt, double r) : center(pt), radius(r) {}
  void draw()
  {
    cout << "Center: " << center.getX() << "," << center.getY() << endl;
    cout << "Radius: " << radius << endl;
  }
  double area() {
    return 3.14 * radius * radius;
  }
};

class Triangle: public Shape
{
private:
  Point2D *vertices;
public:
  Triangle (Point2D *vec) {
    vertices = new Point2D[3];
    for (int i = 0; i < 3; i++)
      vertices[i].setPoint2D(vec[i].getX(), vec[i].getY());
  }
  ~Triangle() 
  {
    if (vertices != NULL)
      delete [] vertices;
  }
  double area ()
  {
    double l = vertices[1].getY() - vertices[0].getY();
    double h = vertices[2].getX() - vertices[0].getX();
    return 0.5 * l * h;
  }
};

class Rectangle: public Shape
{
private:
  Point2D *vertices;
public:
  Rectangle (Point2D *vec) 
  {
    vertices = new Point2D[4];
    for (int i = 0; i < 4; i++)
      vertices[i].setPoint2D(vec[i].getX(), vec[i].getY());
  }
  double area ()
  {
    double l = vertices[2].getY() - vertices[0].getY();
    double h = vertices[2].getX() - vertices[0].getX();
    return l * h;
  }

};
int main()
{
  Point2D pt(3, 4);
  Circle cir(pt, 5);

  Point2D *vec = new Point2D [3];
  vec[0].setPoint2D(1, 1); 
  vec[1].setPoint2D(1, 6);
  vec[2].setPoint2D(8, 1);
  Triangle tri(vec);
  delete []vec;

  vec = new Point2D [4];
  vec[0].setPoint2D(1,1);
  vec[1].setPoint2D(6,1);
  vec[2].setPoint2D(6,6); 
  vec[3].setPoint2D(1,6);
  Rectangle rect(vec);
  delete [] vec;

  Shape *collection[3];
  collection[0] = &cir;
  collection[1] = &tri;
  collection[2] = &rect;
  cout << "Area of Circle: " << collection[0]->area() << endl;
  cout << "Area of Triangle: " << collection[1]->area() << endl;
  cout << "Area of Rectangle: " << collection[2]->area() << endl;
  return 0;
}
