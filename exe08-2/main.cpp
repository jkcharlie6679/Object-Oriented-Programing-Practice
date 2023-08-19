#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
  string inFilePath, outFilePath;
  cout << "Please enter input file name: ";
  cin >> inFilePath;
  cout << "Please enter output file name: ";
  cin >> outFilePath;
  
  ifstream inFile;
  ofstream outFile;
  inFile.open(inFilePath);
  outFile.open(outFilePath);
  if (inFile.fail())
  {
    cout << "Error opening input file." << endl;
    return 1;
  }
  if (outFile.fail())
  {
    cout << "Error opening output file." << endl;
    return 1;
  }
  
  string line;
  int numWords = 0;
  int maxLength = 0;
  string maxWord = "";
  while (inFile >> line)
  {
    if (strlen(line.c_str()) >= maxLength)
    {
      maxLength = strlen(line.c_str());
      maxWord = line;
    }
    numWords++;
  }
  outFile << "The number of words read is " << numWords << endl;
  outFile << "The longest word has a length of " << maxLength << endl;
  outFile << "The longest word is " << maxWord << endl;
  return 0;
}
