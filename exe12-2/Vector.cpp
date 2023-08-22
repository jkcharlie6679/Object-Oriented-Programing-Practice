#include <iostream>
#include "Point2D.h"
#include "Vector.h"

using namespace std;

template <class T>
Vector<T>::Vector()
{
  len = 0;
  vec = NULL;
}

template <class T>
Vector<T>::Vector(int len, int val)
{
  this->len = len;
  this->vec = new T[len];
  for (int i = 0; i < len; i++)
    vec[i] = val;
}

template <class T>
Vector<T>::Vector(int len, T val)
{
  this->len = len;
  vec = new T[len];
  for (int i = 0; i < len; i++)
    vec[i] = val;
}

template <class T>
Vector<T>::Vector(int len, T *vec)
{
  this->len = len;
  this->vec = new T[len];
  for (int i = 0; i < len; i++)
    this->vec[i] = vec[i];
}

template <class T>
void Vector<T>::display()
{
  for (int i = 0; i < len; i++)
  {
    cout << vec[i];
    if (i != len-1)
      cout << ", ";
  }
  cout << endl;
}

template <class T>
Vector<T> Vector<T>::operator+=(const Vector<T> &v)
{
  for (int i = 0; i < len; i++)
    vec[i] += v.vec[i];
  return *this;
}

template <class S>
S dot (const Vector<S> &v1, const Vector<S> &v2)
{
  S sum;
  for (int i = 0; i < v1.len; i++)
    sum += v1.vec[i] * v2.vec[i];
  return sum;
}

