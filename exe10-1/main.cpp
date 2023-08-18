#include <iostream>
#include "shape.h"

using namespace std;

int main()
{
  Point2D p(2, 2);
  Point2D *vec = new Point2D [3];
  vec[0].set(2, 1);
  vec[1].set(8, 1);
  vec[2].set(5, 6);
  Circle_in_Triangle ct(255, p, 1, vec);
  
  ct.draw();
  cout << "Area of Circle: " << ct.Circle::area() << endl;
  cout << "Area of Triangle: " << ct.Triangle::area() << endl;
  cout << "Area of Circle_in_Triangle: " << ct.area() << endl;
  return 0;
}
