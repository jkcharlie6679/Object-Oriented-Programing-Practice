#include <iostream>
#include "Matrix.h"

using namespace std;

matrix::Matrix::Matrix()
{
  n = 0;
  elements = NULL;
}

void matrix::Matrix::assignDimension(int n)
{
  this->n = n;
  this->elements = new int*[n];
  for (int i = 0; i < n; i++)
    this->elements[i] = new int[n];
}

void matrix::Matrix::assignElements()
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      this->elements[i][j] = rand() % 10 + 1;
}

void matrix::Matrix::assignMatrix(Matrix A)
{
  this->n = A.n;
  this->elements = new int*[n];
  for (int i = 0; i < n; i++)
    this->elements[i] = new int[n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      this->elements[i][j] = A.elements[i][j];
}

void matrix::Matrix::transposeMatrix()
{
  int **tElements = new int*[n];
  for (int i = 0; i < n; i++)
    tElements[i] = new int[n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      tElements[i][j] = this->elements[j][i];
  for (int i = 0; i < n; i++)
    delete [] this->elements[i];
  delete [] this->elements;
  this->elements = tElements;
}

void matrix::Matrix::printMatrix()
{
  cout << "[";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // cout << i << j << endl;
      cout << " " << this->elements[i][j];
    }
    cout << ";";
  }
  cout << " ]" ;
}

matrix::Matrix matrix::Matrix::addMatrix(Matrix B)
{
  Matrix C;
  C.assignDimension(this->n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      C.elements[i][j] = this->elements[i][j] + B.elements[i][j];
  return C;
}

matrix::Matrix matrix::Matrix::subtractMatrix(Matrix B)
{
  Matrix C;
  C.assignDimension(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      C.elements[i][j] = this->elements[i][j] - B.elements[i][j];
  return C;
}

matrix::Matrix matrix::Matrix::multiplyMatrix(Matrix B)
{
  Matrix C;
  C.assignDimension(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      C.elements[i][j] = 0;
      for (int k = 0; k < n; k++)
        C.elements[i][j] += this->elements[i][k] * B.elements[k][j];
    }
  return C;
}

