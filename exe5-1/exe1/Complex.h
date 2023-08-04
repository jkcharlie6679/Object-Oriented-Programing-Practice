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
    void assign(double, double);
    void assignReal(double);
    void assignImage(double);
    void printComplex();
    double getReal();
    double getImage();
    Complex add(Complex);
    Complex subtract(Complex);
    Complex multiply(Complex);
    Complex division(Complex);
    // ~Complex();
  };
}
#endif
