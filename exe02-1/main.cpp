#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "student.h"

using namespace std;

static void ReadScores (char *fileName, vector<student::Student*> &students)
{
  ifstream myFile;
  myFile.open(fileName);
  if (!myFile.is_open())
  {
    cout << "Unable to open file" << endl;
    exit(1);
  }
  string studentId;
  string name;
  int score[9];
  int time;
  while (myFile >> studentId >> name >> score[0] >> score[1] >> score[2] >> score[3] >> 
         score[4] >> score[5] >> score[6] >> score[7] >> score[8] >> time)
  {
    int totalScore = 0;
    for (int i = 0; i < 9; i++)
    {
      if (score[i])
      { 
        if (i < 3)
          totalScore += 10;
        else if (i < 6)
          totalScore += 20;
        else
          totalScore += 30;
        if (totalScore > 100)
          totalScore = 100;
      }
    }
    student::Student *newStudent = new student::Student(studentId, name, totalScore, time);
    students.push_back(newStudent);
  }
  myFile.close();
}


static void quickSort(vector<student::Student*> &students, int left, int right)
{
  int i = left, j = right;
  int pivotScore = students[(left + right) / 2]->getScore();
  int pivotTime = students[(left + right) / 2]->getTime();
  while (i <= j)
  {
    while (students[i]->getScore() < pivotScore || students[i]->getScore() == pivotScore && students[i]->getTime() > pivotTime)
      i++;
    while (students[j]->getScore() > pivotScore || students[j]->getScore() == pivotScore && students[j]->getTime() < pivotTime)
      j--;
    if (i <= j)
    {
      student::Student *temp = students[i];
      students[i] = students[j];
      students[j] = temp;
      i++;
      j--;
    }
  }
  if (left < j)
    quickSort(students, left, j);
  if (i < right)
    quickSort(students, i, right);
}

static void SortScores (vector<student::Student*> &students)
{
  quickSort(students, 0, students.size() - 1);
}

static void PrintScores(char *fileName, vector<student::Student*> &students)
{
  ofstream myFile;
  myFile.open(fileName);
  if (!myFile.is_open())
  {
    cout << "Unable to open file" << endl;
    exit(1);
  }
  for (int i = students.size() - 1; i >= 0; i--)
  {
    myFile << students[i]->getStudentId() << " " << students[i]->getName() << " " << 
      students[i]->getScore() << " " << students[i]->getTime() << endl;
  }
  myFile.close();
}

int main (int argc, char *argv[])
{
  vector<student::Student*> students;
  ReadScores(argv[1], students);
  SortScores(students);
  PrintScores(argv[2], students);
  return 0;
}

