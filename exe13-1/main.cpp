#include <cstdlib>
#include <iostream>
#include <vector>
#include "complex.hpp"

using namespace std;

int main ()
{
  cout << "Enter n: ";
  int n;
  cin >> n;
  vector<Complex> v(n);
  for (int i = 0; i < n; i++)
    v[i].setNumber((double)(rand() % 10 + (double)(rand() % 100) / 100), (double)(rand() % 10 + (double)(rand() % 100) / 100));
  cout << "Original sequence:" << endl;
  for (int i = 0; i < n; i++)
    cout << v[i];
  cout << endl;
  sort(v.begin(), v.end());
  cout << "Sorted sequence:" << endl;
  for (int i = 0; i < n; i++)
    cout << v[i];
  cout << endl;
  return 0;
}
