#ifndef QUADRANGLE_H
#define QUADRANGLE_H

namespace quadrangleNS
{
  class quadrangle
  {
  public:
    class vertex
    {
    friend class quadrangle;
    private:
      int x;
      int y;
    public:
      vertex();
      vertex(int x, int y);
    };
    quadrangle();
    quadrangle(vertex v1, vertex v2);
    quadrangle(vertex v1, vertex v2, vertex v3, vertex v4);
    void draw();
    void move(vertex v);
    static vertex origin;
  private:
    vertex v[4];
    bool isRectangle;
  };
}

#endif // QUADRANGLE_H

