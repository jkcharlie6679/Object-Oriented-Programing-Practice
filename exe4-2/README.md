# MATRIX OPERATION

Write a class called Matrix to perform matrix arithmetic. The sample output is shown as follows.

```text
Enter n for n x n matrix: 3
A = [10 2 8; 1 5 8; 1 4 8];
B = [7 4 7; 3 2 6; 6 9 10];
A’ = [10 1 1; 2 5 4; 8 8 8];
B’ = [7 3 6; 4 2 9; 7 6 10];
A + B = [17 6 15; 4 7 14; 7 13 18];
A – B = [3 -2 1; -2 3 2; -5 -5 -2];
A * B = [124 116 162; 70 86 117; 67 84 111];
```

The elements (integer) in matrix is randomly generated in range [1,10]. The representation of matrix is row major. For example, A = [10 2 8; 1 5 8; 1 4 8] indicates that

$a = \begin{bmatrix}
10 & 2 & 8\\
1 & 5 & 8\\
1 & 4 & 8
\end{bmatrix}$


The main structure of the program is like as,

```cpp
// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H
/* Write class definition for Matrix */
#endif
```

```cpp
// Matrix.cpp
#include <iostream>
using std::cout;
#include "Matrix.h"
// Member-function definitions for class Matrix.
```

```cpp
// ex4-2.cpp
#include <iostream>
using std::cout;
using std::endl;
#include "Matrix.h"
int main()
{
  int n;
  cout << “Enter n for n x n matrix: ” << endl;
  cin >> n;

  Matrix A, B, C; // create three Matrix objects
  A.assignDimension(n);
  A.assignElements(); // assign elements in Matrix A randomly
  cout << "A = ";
  A.printMatrix(); // output object A
  cout << endl;

  B.assignDimension(n);
  B.assignElements(); // assign elements in Matrix B randomly
  cout << "B = ";
  B.printMatrix(); // output object B
  cout << endl;

  Matrix tA;
  tA.assignMatrix(A); // copy elements and dimension from A
  tA.transposeMatrix(); // transpose Matrix tA
  cout << "A’ = ";
  tA.printMatrix(); // output object tA
  cout << endl;

  Matrix tB;
  tB.assignMatrix(B); // copy elements and dimension from B
  tB.transposeMatrix(); // transpose Matrix tB
  cout << "B’ = ";
  tB.printMatrix(); // output object tB
  cout << endl;

  C = A.addMatrix(B); // C = A + B
  cout << "A+B = ";
  C.printMatrix(); // output object C
  cout << endl;

  C = A.subtractMatrix(B); // C = A - B
  cout << "A-B = ";
  C.printMatrix(); // output object C
  cout << endl;

  C = A.multiplyMatrix(B); // C = A * B
  cout << "A*B = ";
  C.printMatrix(); // output object C
  cout << endl;

  return 0;
}
```

## Reference

[NYCU OCW Object-Oriented Programming Lab 04](https://ocw.nycu.edu.tw/course/oop002/LAB_04.pdf)

