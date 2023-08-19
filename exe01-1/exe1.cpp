#include <iostream>
#include <fstream>
#include "exe1.h"

using namespace std;

void ReadTextFile(char *filename, Cplex &a, Cplex &b)
{
  ifstream myFile;
  myFile.open(filename);
  if (myFile.is_open()) {
    string line;
    getline(myFile, line);
    if (line.find('+') != -1)
    {
      a.real = stod(line.substr(0, line.find('+')));
      a.image = stod(line.substr(line.find('+') + 1, line.size()-line.find('+') - 2));
    }
    else
    {
      if (line[0] == '-')
      {
        line = line.substr(1, line.size() - 1);
        a.real = -stod(line.substr(0, line.find('-')));
        if (line.find('-') != -1)
          a.image = -stod(line.substr(line.find('-') + 1, line.size()-line.find('-') - 2));
        else
          a.image = stod(line.substr(line.find('+') + 1, line.size()-line.find('-') - 2));
      }
      else
      {
        a.real = stod(line.substr(0, line.find('-')));
        a.image = -stod(line.substr(line.find('-') + 1, line.size()-line.find('-') - 2));
      }
    }
    getline(myFile, line);
    if (line.find('+') != -1)
    {
      b.real = stod(line.substr(0, line.find('+')));
      b.image = stod(line.substr(line.find('+') + 1, line.size()-line.find('+') - 2));
    }
    else
    {
      if (line[0] == '-')
      {
        line = line.substr(1, line.size() - 1);
        b.real = -stod(line.substr(0, line.find('-')));
        if (line.find('-') != -1)
          b.image = -stod(line.substr(line.find('-') + 1, line.size()-line.find('-') - 2));
        else
          b.image = stod(line.substr(line.find('+') + 1, line.size()-line.find('-') - 2));
      }
      else
      {
        b.real = stod(line.substr(0, line.find('-')));
        b.image = -stod(line.substr(line.find('-') + 1, line.size()-line.find('-') - 2));
      }
    }
    myFile.close();
  }
  else {
    cout << "Unable to open file";
  }
}

Cplex ComplexOperation(Cplex &a, Cplex &b, char op)
{
  Cplex res;
  switch (op) {
    case '+':
      res.real = a.real + b.real;
      res.image = a.image + b.image;
      break;
    case '-':
      res.real = a.real - b.real;
      res.image = a.image - b.image;
      break;
    case '*':
      res.real = a.real * b.real - a.image * b.image;
      res.image = a.real * b.image + a.image * b.real;
      break;
    case '/':
      res.real = (a.real * b.real + a.image * b.image) / (b.real * b.real + b.image * b.image);
      res.image = (a.image * b.real - a.real * b.image) / (b.real * b.real + b.image * b.image);
      break;
  
  }
  return res;
}

void PrintComplex(char *filename, Cplex *res)
{
  ofstream myFile;
  myFile.open(filename);
  myFile << fixed << setprecision(3);
  if (myFile.is_open()) {
    for (int i = 0; i < 4; i++)
    {
      myFile << res[i].real << "+" << res[i].image << 'i' << endl;
    }
    myFile.close();
  }
  else {
    cout << "Unable to open file";
  }
}

