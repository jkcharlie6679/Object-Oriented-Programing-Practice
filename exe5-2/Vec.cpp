#include <iostream>
#include "Vec.h"

using namespace std;

Vec::Vec()
{
  array = NULL;
  dim = 0;
}

Vec::Vec(int *array, int dim)
{
  this->array = new int[dim];
  this->dim = dim;
  for (int i = 0; i < dim; i++)
    this->array[i] = array[i];
}

// Vec::~Vec()
// {
//   delete[] array;
// }

void Vec::assign(int *array, int dim)
{
  this->array = new int[dim];
  this->dim = dim;
  for (int i = 0; i < dim; i++)
    this->array[i] = array[i];
}

void Vec::printVec()
{
  for (int i = 0; i < dim; i++)
    cout << array[i] << " ";
  cout << endl;
}

void Vec::sort()
{
  for (int i = 0; i < dim; i++)
    for (int j = i + 1; j < dim; j++)
      if (array[i] > array[j])
      {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
}

bool Vec::isEqual(Vec vec)
{
  if (dim != vec.dim)
    return false;
  for (int i = 0; i < dim; i++)
    if (array[i] != vec.array[i])
      return false;
  return true;
}

void Vec::unionSet(Vec vec1, Vec vec2)
{
  this->array = new int[vec1.dim + vec2.dim];
  this->dim = vec1.dim + vec2.dim;
  for (int i = 0; i < vec1.dim; i++)
    array[i] = vec1.array[i];
  for (int i = 0; i < vec2.dim; i++)
    array[vec1.dim + i] = vec2.array[i];
}

Vec Vec::inpendetSet()
{
  Vec temp;
  temp.assign(array, dim);
  temp.sort();
  for (int i = 0; i < temp.dim - 1; i++)
    if (temp.array[i] == temp.array[i + 1])
    {
      for (int j = i; j < temp.dim - 1; j++)
        temp.array[j] = temp.array[j + 1];
      temp.dim--;
      i--;
    }
  return temp;
}

int Vec::min()
{
  int min = array[0];
  for (int i = 1; i < dim; i++)
    if (array[i] < min)
      min = array[i];
  return min;
}

int Vec::max()
{
  int max = array[0];
  for (int i = 1; i < dim; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

bool Vec::find(int target)
{
  for (int i = 0; i < dim; i++)
    if (array[i] == target)
      return true;
  return false;
}



