#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

using namespace std;

class Complex
{
private:
  double real;
  double imag;
public:
  Complex();
  Complex(double r, double i);
  void setNumber(double r, double i);
  friend bool operator<(const Complex& c1, const Complex& c2);
  friend ostream& operator<<(ostream& os, const Complex& c);
};

ostream& operator<<(ostream& os, const Complex& c);
bool operator<(const Complex& c1, const Complex& c2);
#endif // COMPLEX_HPP
