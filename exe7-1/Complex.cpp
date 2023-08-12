#include <ios>
#include <iostream>
#include "Complex.h"
#include <iomanip>

using namespace std;

complex::Complex::Complex()
{
  real = 0;
  image = 0;
}

complex::Complex::Complex(const complex::Complex &c)
{
  real = c.real;
  image = c.image;
}

complex::Complex::Complex(double realIn, double imageIn)
{
  real = realIn;
  image = imageIn;
} 

void complex::Complex::setComplexNumber(double realIn, double imageIn)
{
  real = realIn;
  image = imageIn;
}

void complex::Complex::assignReal(double realIn)
{
  real = realIn;
}

void complex::Complex::assignImage(double imageIn)
{
  image = imageIn;
}

void complex::printComplex(complex::Complex c)
{
  if (c.image < 0)
    cout << fixed << setprecision(1) << "(" << c.real << " " << c.image << "i" << ")" ; 
  else
    cout << fixed << setprecision(1) << "(" << c.real << " + " << c.image << "i" << ")" ; 
}


void complex::printMeg(complex::Complex a, complex::Complex b, char op)
{
  complex::printComplex(a);
  cout << " " << op << " ";
  complex::printComplex(b);
  cout << " = ";
}

complex::Complex complex::Complex::add(complex::Complex c)
{
  complex::Complex result;
  result.real = real + c.real;
  result.image = image + c.image;
  return result;
}

complex::Complex complex::Complex::subtract(complex::Complex c)
{
  complex::Complex result;
  result.real = real - c.real;
  result.image = image - c.image;
  return result;
}

complex::Complex complex::Complex::multiply(complex::Complex c)
{
  complex::Complex result;
  result.real = real * c.real - image * c.image;
  result.image = real * c.image + image * c.real;
  return result;
}

complex::Complex complex::Complex::division(complex::Complex c)
{
  complex::Complex result;
  result.real = (real * c.real + image * c.image) / (c.real * c.real + c.image * c.image);
  result.image = (image * c.real - real * c.image) / (c.real * c.real + c.image * c.image);
  return result;
}

complex::Complex complex::Complex::operator+(const complex::Complex &c)
{
  return add(c);
}

complex::Complex complex::Complex::operator-(const complex::Complex &c)
{
  return subtract(c);
}

complex::Complex complex::Complex::operator*(const complex::Complex &c)
{
  return multiply(c);
}

complex::Complex complex::Complex::operator/(const complex::Complex &c)
{
  return division(c);
}

complex::Complex complex::Complex::operator-()
{
  Complex result;
  result.real = -real;
  result.image = -image;
  return result;
}
