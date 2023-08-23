#include <iostream>
#include "complex.hpp"

using namespace std;

Complex::Complex()
{
  real = 0;
  imag = 0;
}

Complex::Complex(double r, double i)
{
  real = r;
  imag = i;
}

void Complex::setNumber(double r, double i)
{
  real = r;
  imag = i;
}

ostream& operator<<(ostream& os, const Complex& c)
{
  os << "(" << c.real << " + " << c.imag << "i" << ")";
  return os;
}

bool operator<(const Complex& c1, const Complex& c2)
{
  return c1.real < c2.real || (c1.real == c2.real && c1.imag < c2.imag);
}
