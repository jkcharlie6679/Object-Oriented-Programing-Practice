#include "poly.h"
#include <cctype>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void poly::ReadTextFile(char *fileName, Poly &eq)
{
  ifstream myFile;
  myFile.open(fileName);
  memset(eq.items, 0, sizeof(eq.items));
  if (myFile.is_open())
  {
    string line;
    getline(myFile, line);
    for (int i = 0, power = 0, coeff = 0; i < line.length(); coeff = 0, power = 0)
    {
      bool isNeg = false;
      if (line[i] == '-')
      {
        isNeg = true;
        i++;
      }
      else if (line[i] == '+')
        i++;
      while (isdigit(line[i]))
        coeff = coeff * 10 + line[i++] - '0';
      if (isNeg)
        coeff *= -1;
      if (line[i] == 'X')
      {
        if (line[i + 1] != '^' || i == line.length() - 1)
        {
          i++;
          power = 1;
        }
        else 
        {
          i += 2;
          while (isdigit(line[i]))
            power = power * 10 + line[i++] - '0';
        }
      }
      eq.num_items = max(eq.num_items, power + 1);
      eq.items[power].coeff = coeff;
      eq.items[power].power = power;
    }
    myFile.close();
  }
  else
    cout << "Unable to open file";
}

void poly::DifferentationPoly(Poly &eq)
{
  for (int i = 0; i < eq.num_items - 1; i++)
  {
    eq.items[i].coeff = eq.items[i + 1].coeff * (i + 1);
    if (eq.items[i].coeff != 0)
      eq.items[i].power = eq.items[i + 1].power - 1;
  }
  eq.items[eq.num_items - 1].power = 0;
  eq.items[eq.num_items - 1].coeff = 0;
  eq.num_items--;
}

void poly::PrintComplex(char *fileName, Poly &eq)
{
  ofstream myFile;
  myFile.open(fileName);
  if (myFile.is_open())
  {
    for (int i = eq.num_items - 1; i >= 0; i--)
    {
      if (eq.items[i].coeff != 0)
      {
        if (eq.items[i].coeff > 0 && i != eq.num_items - 1)
          myFile << "+";
        myFile << eq.items[i].coeff;
        if (eq.items[i].power != 0 && i != 0)
        {
          myFile << "X";
          if (eq.items[i].power != 1)
            myFile << "^" << eq.items[i].power;
        }
      }
    }
    myFile << endl;
    myFile.close();
  }
}


