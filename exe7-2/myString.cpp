#include <iostream>
#include "myString.h"

using namespace std;

myString::string::string()
{
  p = NULL;
}

myString::string::string (const char *s)
{
  int len = strlen(s);
  p = new char[len+1];
  strcpy(p, s);
}

myString::string::string (const string &s)
{
  int len = strlen(s.p);
  p = new char[len+1];
  strcpy(p, s.p);
}

myString::string::~string()
{
  if (p)
    delete [] p;
}

ostream& myString::operator << (ostream& os, const string &s)
{
  os << s.p;
  return os;
}

myString::string myString::operator + (const string &s, const string &t)
{
  string temp;
  int len = strlen(s.p) + strlen(t.p);
  temp.p = new char[len+1];
  strcpy(temp.p, s.p);
  strcat(temp.p, t.p);
  return temp;
}

bool myString::string::operator <= (const string &s)
{
  if (strcmp(p, s.p) <= 0)
    return true;
  else
    return false;
}

