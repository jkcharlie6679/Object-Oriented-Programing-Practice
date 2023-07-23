#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef struct
{
  int *data;
  int length;
  bool sign;
} BIGNUMBER;

static void ReadTextFile (char* fileName, BIGNUMBER &a, BIGNUMBER &b)
{
  ifstream inFile(fileName);
  if (inFile.is_open())
  {
    string line;
    getline(inFile, line);
    if (line[0] == '-')
    {
      a.sign = false;
      line.erase(0, 1);
    }
    else
      a.sign = true;
    a.length = line.length();
    a.data = new int[line.length()];
    for (int i = 0; i < line.length(); i++)
      a.data[line.length() - i - 1] = line[i] - '0';

    getline(inFile, line);
    if (line[0] == '-')
    {
      b.sign = false;
      line.erase(0, 1);
    }
    else
      b.sign = true;
    b.length = line.length();
    b.data = new int[line.length()];
    for (int i = 0; i < line.length(); i++)
      b.data[line.length() - i - 1] = line[i] - '0';
  }
  else
    cout << "Unable to open file";
}

static int swapNumberOrNot (BIGNUMBER &a, BIGNUMBER &b)
{
  if (a.length < b.length)
    return 1;
  else if (a.length > b.length)
    return -1;
  else
  {
    for (int i = a.length - 1; i >= 0; i--)
    {
      if (a.data[i] > b.data[i])
        return 1;
      else if (a.data[i] < b.data[i])
        return -1;
    }
    return 0;
  }
}

static BIGNUMBER BigNumberOperation(BIGNUMBER &a, BIGNUMBER &b, char opr)
{
  BIGNUMBER result;
  if (opr == '-')
    b.sign = !b.sign;
  string calResult;
  if (a.sign == b.sign)
  {
    result.sign = a.sign;
    for (int i = 0, j = 0, carry = 0; i < a.length || j < b.length; i++, j++)
    {
      if (i < a.length && j < b.length)
      {
        int temp = a.data[i] + b.data[j] + carry;
        if (temp >= 10)
        {
          calResult += (temp - 10) + '0';
          carry = 1;
        }
        else
        {
          calResult += temp + '0';
          carry = 0;
        }
      }
      else if (i < a.length)
        calResult += a.data[i] + '0';
      else
        calResult += b.data[j] + '0';
    }
      }
  else
  {
    int swapOrNot = swapNumberOrNot(a, b);
    if (swapOrNot == 0)
    {
      result.sign = true;
      calResult = "0";
    }
    else
    {
      if (a.sign == false && swapOrNot == 1 || a.sign == true && swapOrNot == -1)
        result.sign = true;
      else
        result.sign = false;
      if (swapOrNot == 1)
        swap(a, b);
      for (int i = 0, j = 0; i < a.length || j < b.length; i++, j++)
      {
        if (j < b.length)
        {
          if (a.data[i] < b.data[i])
          {
            a.data[i + 1]--;
            int temp = a.data[i] + 10 - b.data[j];
            calResult += temp + '0';
          }
          else
          {
            int temp = a.data[i] - b.data[j];
            calResult += temp + '0';
          }
        }
        else
          calResult += a.data[i] + '0';
      }
    }
    if (swapOrNot == 1)
      swap(a, b); 
  }
  result.length = calResult.length();
  result.data = new int[calResult.length()];
  for (int i = calResult.length() - 1; i >= 0; i--)
    result.data[i] = calResult[i] - '0';

  return result;
}

static void WriteResults(char* fileName, BIGNUMBER results[])
{
  ofstream outFile(fileName);
  if (outFile.is_open())
  {
    for (int i = 0; i < 2; i++)
    {
      if (results[i].sign == false)
        outFile << '-';
      for (int j = results[i].length - 1; j >= 0; j--)
        outFile << results[i].data[j];
      outFile << endl;
    }
  }
  else
    cout << "Unable to open file";
}

int main (int argc, char *argv[])
{
  BIGNUMBER a, b;
  ReadTextFile(argv[1], a, b);
  BIGNUMBER results[2];
  results[0] = BigNumberOperation(a, b, '+');
  results[1] = BigNumberOperation(a, b, '-');
  WriteResults(argv[2], results);
  return 0;
}

