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
protected:
  int color;
public:
  virtual void draw() = 0;
  virtual bool is_closed() = 0;
  virtual ~Shape(){}
};

class Circle: public Shape
{
private:
  Point2D center;
  double radius;
public:
  Circle(Point2D pt, double r, int c) : center(pt), radius(r) {
    color = c;
  }
  void draw()
  {
    cout << "Color: " << color << endl;
    cout << "Center: " << center.getX() << "," << center.getY() << endl;
    cout << "Radius: " << radius << endl;
  }
  bool is_closed() {return true;}
  ~Circle(){}
};

class Polygon: public Shape
{
public:
  bool is_closed() {return true;}
};

class Triangle: public Polygon
{
private:
  Point2D *vertices;
public:
  Triangle(Point2D *vec, int c) {
    vertices = new Point2D[3];
    for (int i = 0; i < 3; i++)
      vertices[i].setPoint2D(vec[i].getX(), vec[i].getY());
    color = c;
  }
  ~Triangle() {
    if (vertices != NULL)
      delete [] vertices;
  }
  void draw() {
    cout << "Color: " << color << endl;
    cout << "Vertices: " << endl;
    for (int i = 0; i < 3; i++) {
      vertices[i].display();
      cout << endl;
    }
  }
  bool is_closed() {return true;}
};

int main()
{
  // task A
  Point2D pt(3, 4);
  Circle c(pt, 5, 255);
  c.draw();
  // task B
  Point2D *vec = new Point2D[3];
  vec[0].setPoint2D(1,1);
  vec[1].setPoint2D(6,1);
  vec[2].setPoint2D(1,8);
  Triangle t(vec,255);
  delete []vec;
  t.draw();
  
  return 0;
}
