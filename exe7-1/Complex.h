#ifndef COMPLEX_H
#define COMPLEX_H

namespace complex {
  class Complex {
  private:
    double real;
    double image;
  public:
    Complex();
    Complex(double, double);
    Complex(const complex::Complex &c);
    void setComplexNumber(double, double);
    void assignReal(double);
    void assignImage(double);
    friend void printComplex(Complex);
    friend void printMeg(Complex, Complex, char);
    double getReal();
    double getImage();
    Complex add(Complex);
    Complex subtract(Complex);
    Complex multiply(Complex);
    Complex division(Complex);
    Complex operator+(const Complex &);
    Complex operator-(const Complex &);
    Complex operator*(const Complex &);
    Complex operator/(const Complex &);
    Complex operator-();
    // ~Complex();
  };
  void printComplex(Complex);
  void printMeg(Complex, Complex, char);
}
#endif
