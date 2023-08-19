#include <iostream>
#include <cmath>
#include "quadrangle.h"

using namespace std;
using namespace quadrangleNS;

quadrangle::vertex quadrangle::origin(0, 0);

quadrangle::vertex::vertex()
{
  this->x = 0;
  this->y = 0;
}

quadrangle::vertex::vertex(int x, int y)
{
  this->x = x;
  this->y = y;
}

quadrangle::quadrangle()
{
  this->isRectangle = false;
  this->v[0] = vertex(0, 0);
  this->v[1] = vertex(0, 0);
  this->v[2] = vertex(0, 0);
  this->v[3] = vertex(0, 0);
}

quadrangle::quadrangle(vertex v1, vertex v2)
{
  this->isRectangle = true;
  this->v[0] = v1;
  this->v[1] = vertex(v2.x, v1.y);
  this->v[2] = v2;
  this->v[3] = vertex(v1.x, v2.y);
}

quadrangle::quadrangle(vertex v1, vertex v2, vertex v3, vertex v4)
{
  this->isRectangle = false;
  this->v[0] = v1;
  this->v[1] = v2;
  this->v[2] = v3;
  this->v[3] = v4;
}

void quadrangle::draw()
{
  cout << "v1: (" << v[0].x << ", " << v[0].y << ") ";
  cout << "v2: (" << v[1].x << ", " << v[1].y << ") ";
  cout << "v3: (" << v[2].x << ", " << v[2].y << ") ";
  cout << "v4: (" << v[3].x << ", " << v[3].y << ") ";
  if (isRectangle)
    cout << "Area: " << (v[2].x - v[0].x) * (v[2].y - v[0].y);
}

void quadrangle::move(vertex v)
{
  cout << "Distance: " << sqrt(pow((origin.x - v.x), 2) + pow((origin.y - v.y), 2)) << endl;
  int dx = v.x - this->v[0].x;
  int dy = v.y - this->v[0].y;
  this->v[0].x += dx;
  this->v[0].y += dy;
  this->v[1].x += dx;
  this->v[1].y += dy;
  this->v[2].x += dx;
  this->v[2].y += dy;
  this->v[3].x += dx;
  this->v[3].y += dy;
}

