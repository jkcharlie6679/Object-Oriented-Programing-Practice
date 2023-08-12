#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

using namespace std;

namespace myString
{
  class string
  {
  private:
    char *p;
  public:
    string();
    string (const char *s);
    string (const string &s);
    ~string(); 
    friend ostream& operator << (ostream&, const string &s);
    friend string operator + (const string &s, const string &t);
    bool operator <= (const string &s);
  };
  ostream& operator << (ostream&, const string &s);
  string operator + (const string &s, const string &t);
}
#endif

