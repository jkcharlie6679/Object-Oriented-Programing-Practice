#include <iostream>
#include "matrix.h"

using namespace std;

FullMatrix::FullMatrix (int n)
{
  dim = n;
  matrix = new int*[dim];
  for (int i = 0; i < dim; i++)
    matrix[i] = new int[dim];
}

int &FullMatrix::operator() (int i, int j)
{
  if (i >= dim || j >= dim)
  {
    cout << "Index out of range!" << endl;
    exit(1);
  }
  return matrix[i][j];
}

const int &FullMatrix::operator() (int i, int j) const
{
  if (i >= dim || j >= dim)
  {
    cout << "Index out of range!" << endl;
    exit(1);
  }
  return matrix[i][j];
}

void FullMatrix::showMatrix () const
{
  for (int i = 0; i < dim; i++)
  {
    for (int j = 0; j < dim; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
}

FullMatrix::~FullMatrix ()
{
  for (int i = 0; i < dim; i++)
    delete [] matrix[i];
  delete [] matrix;
}

SymmetricMatrix::SymmetricMatrix (int n)
{
  dim = n;
  matrix = new int*[dim];
  for (int i = 0; i < dim; i++)
    matrix[i] = new int[dim];
}

int &SymmetricMatrix::operator() (int i, int j)
{
  if (i >= dim || j >= dim)
  {
    cout << "Index out of range!" << endl;
    exit(1);
  }
  return (i >= j) ? matrix[i][j] : matrix[j][i];
}

const int &SymmetricMatrix::operator() (int i, int j) const
{
  if (i >= dim || j >= dim)
  {
    cout << "Index out of range!" << endl;
    exit(1);
  }
  return (i >= j) ? matrix[i][j] : matrix[j][i];
}

void SymmetricMatrix::showMatrix () const
{
  for (int i = 0; i < dim; i++)
  {
    for (int j = 0; j < dim; j++)
      cout << this->operator() (i, j) << " ";
    cout << endl;
  }
}

int &SymmetricMatrix::getElem (int i, int j) const
{
  return matrix[i][j];
}

LowTriMatrix::LowTriMatrix (int n): SymmetricMatrix(n) {}

int &LowTriMatrix::operator() (int i, int j)
{
  if (i >= dim || j >= dim || i < j)
  {
    cout << "Index out of range!" << endl;
    exit(1);
  }
  return getElem(i, j);
}

SymmetricMatrix::~SymmetricMatrix ()
{
  for (int i = 0; i < dim; i++)
    delete [] matrix[i];
  delete [] matrix;
}

const int &LowTriMatrix::operator() (int i, int j) const
{
  if (i >= dim || j >= dim || i < j)
  {
    cout << "Index out of range!" << endl;
    exit(1);
  }
  return getElem(i, j);
}

void LowTriMatrix::showMatrix () const
{
  for (int i = 0; i < dim; i++)
  {
    for (int j = 0; j < dim; j++)
      cout << getElem(i, j) << " ";
    cout << endl;
  }
}

UpperTriMatrix::UpperTriMatrix (int n): SymmetricMatrix(n) {}

int &UpperTriMatrix::operator() (int i, int j)
{
  if (i >= dim || j >= dim || i > j)
  {
    cout << "Index out of range!" << endl;
    exit(1);
  }
  return getElem(i, j);
}

const int &UpperTriMatrix::operator() (int i, int j) const
{
  if (i >= dim || j >= dim || i > j)
  {
    cout << "Index out of range!" << endl;
    exit(1);
  }
  return getElem(i, j);
}

void UpperTriMatrix::showMatrix () const
{
  for (int i = 0; i < dim; i++)
  {
    for (int j = 0; j < dim; j++)
      cout << getElem(i, j) << " ";
    cout << endl;
  }
}

