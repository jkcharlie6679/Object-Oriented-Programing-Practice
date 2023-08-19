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

complex::Complex::Complex(double realIn, double imageIn)
{
  real = realIn;
  image = imageIn;
} 

void complex::Complex::assign(double realIn, double imageIn)
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

void complex::Complex::printComplex()
{
  cout << fixed << setprecision(1) << "(" << real << " + " << image << "i" << ")" ; 
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
