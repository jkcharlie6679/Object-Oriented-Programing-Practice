#include <iostream>
#include "myString.h"

using namespace std;

int main()
{
  string t1("New");
  cout << "t1=" << t1 << endl;
  string t2 = "York";
  cout << "t2=" << t2 << endl;
  string t3 = t1 + " " + t2;
  cout << "t3=" << t3 << endl;
  if ( t1 <= t2 )
    cout << t1 << " is smaller than " << t2 << endl;
  else
    cout << t1 << " is bigger than " << t2 << endl;
  return 0;
}

