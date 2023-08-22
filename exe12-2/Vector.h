#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector
{
private:
  int len;
  T* vec;
public:
  Vector();
  Vector(int, T);
  Vector(int, T*);
  Vector(int, int);
  void display();
  Vector<T> operator+=(const Vector<T> &);
  template<class S>
  friend S dot (const Vector<S> &, const Vector<S> &);
};

template <class S>
S dot (const Vector<S> &v1, const Vector<S> &v2);

#include "Vector.cpp"

#endif

