# COMPLEX NUMBER

Create a Complex class to perform complex number arithmetic and write a program to test your class. The class provides four complex operations: addition, subtraction, multiplication and division. The sample output is shown as follows.

```text
(1.0, 7.0) + (9.0, 2.0) = (10.0, 9.0)
(1.0, 7.0) - (9.0, 2.0) = (-8.0, 5.0)
(1.0, 7.0) * (9.0, 2.0) = (-5.0, 65.0)
(1.0, 7.0) / (9.0, 2.0) = (0.3, 0.7)
(10.0, 7.0) - (9.0, -1.0) = (1.0, 8.0)
```

The main structure of the program is like as,

```cpp
// Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H
/* Write class definition for Complex */
#endif
```

```cpp
// Complex.cpp
#include <iostream>
using std::cout;
#include "Complex.h"
// Member-function definitions for class Complex.
```

```cpp
// ex4-1.cpp
#include <iostream>
using std::cout;
using std::endl;
#include "Complex.h"
int main()
{
  Complex a, b, c; // create three Complex objects
  a.assign(1.0,7.0);
  b.assign(9.0,2.0);
  a.printComplex(); // output object a
  cout << " + ";
  b.printComplex(); // output object b
  cout << " = ";
  c = a.add(b); // invoke add function and assign to object c
  c.printComplex(); // output object c
  cout << endl;

  a.printComplex(); // output object a
  cout << " - ";
  b.printComplex(); // output object b
  cout << " = ";
  c = a.subtract(b); // invoke subtract function and assign to object c
  c.printComplex(); // output object c
  cout << endl;

  a.printComplex(); // output object a
  cout << " * ";
  b.printComplex(); // output object b
  cout << " = ";
  c = a.multiply(b); // invoke multiply function and assign to object c
  c.printComplex(); // output object c
  cout << endl;

  a.printComplex(); // output object a
  cout << " / ";
  b.printComplex(); // output object b
  cout << " = ";
  c = a.division(b); // invoke division function and assign to object c
  c.printComplex(); // output object c
  cout << endl;

  a.assignReal(10.0); // reset object a
  b.assignImage(-1.0); // reset object b

  a.printComplex(); // output object a
  cout << " - ";
  b.printComplex(); // output object b
  cout << " = ";
  c = a.subtract( b ); // invoke subtract function and assign to object c
  c.printComplex(); // output object c
  cout << endl;
  return 0;
}
```

## Reference

[NYCU OCW Object-Oriented Programming Lab 03](https://ocw.nycu.edu.tw/course/oop002/LAB_03.pdf)

