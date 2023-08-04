#include <iostream>
#include "Matrix.h"

using namespace std;

matrix::Matrix::Matrix()
{
  n = 0;
  elements = NULL;
}

matrix::Matrix::Matrix(int n)
{
  this->n = n;
  elements = new int*[n];
  for (int i = 0; i < n; i++)
    elements[i] = new int[n];
}

matrix::Matrix::Matrix(const matrix::Matrix &m)
{
  n = m.n;
  elements = new int*[n];
  for (int i = 0; i < n; i++)
    elements[i] = new int[n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      elements[i][j] = m.elements[i][j];
}

matrix::Matrix::~Matrix()
{
  for (int i = 0; i < n; i++)
    delete [] elements[i];
  delete [] elements;
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
      cout << " " << this->elements[i][j];
    }
    cout << ";";
  }
  cout << " ]" ;
}

void matrix::Matrix::addMatrix(Matrix A, Matrix B)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      this->elements[i][j] = A.elements[i][j] + B.elements[i][j];
}

void matrix::Matrix::subtractMatrix(Matrix A, Matrix B)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      this->elements[i][j] = A.elements[i][j] - B.elements[i][j];
}

void matrix::Matrix::multiplyMatrix(Matrix A, Matrix B)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) 
      for (int k = 0; k < n; k++)
        this->elements[i][j] += A.elements[i][k] * B.elements[k][j];
}

