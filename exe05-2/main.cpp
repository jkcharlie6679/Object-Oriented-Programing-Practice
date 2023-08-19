#include <iostream>
#include <vector>
#include "Vec.h"

using namespace std;

int *getInput(int &dim)
{
  int input;
  vector<int> pool;
  while (1)
  {
    cin >> input;
    if (input == -1)
    {
      dim = pool.size();
      int *array = new int[dim];
      for (int i = 0; i < dim; i++)
        array[i] = pool[i];
      return array;
    }
    else
      pool.push_back(input);
  }
}

int main()
{
  int *array1, *array2;
  int dim1, dim2;

  cout << "Enter the dimension of array1 (-1 to end): ";
  array1 = getInput(dim1);
  cout << "Enter the dimension of array2 (-1 to end): ";
  array2 = getInput(dim2);

  Vec vec1(array1, dim1);
  Vec vec2;
  vec2.assign(array2, dim2);
  cout << "vec1(sorted): ";
  vec1.sort();
  vec1.printVec();

  cout << "vec2(sorted): ";
  vec2.sort();
  vec2.printVec();

  bool isEqual = vec1.isEqual(vec2);
  if (isEqual)
    cout << "vec1 and vec2 are the same." << endl;
  else
    cout << "vec1 and vec2 are not the same." << endl;

  Vec vec3;
  vec3.unionSet(vec1, vec2); // vec3 is union set of vec1 and vec2
  cout << "vec3: ";
  vec3.printVec();
  vec3.sort();
  cout << "vec3(sorted): ";
  vec3.printVec();
  cout << "Min in vec1 and vec2: " << vec3.min() << endl;
  cout << "Max in vec1 and vec2: " << vec3.max() << endl;
  int target = 10;
  bool findInVec = vec3.find(target);
  if (findInVec)
    cout << "Target " << target << " is found in vec3." << endl;
  else
    cout << "Target " << target << " is not found in vec3." << endl;

  Vec vec4;
  vec4 = vec3.inpendetSet();
  cout << "vec4: ";
  vec4.printVec();

  delete [] array1;
  delete [] array2;
  return 0;
}
