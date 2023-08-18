#include <iostream>
#include <fstream>
#include "school.h"

using namespace std;

// test

void test::setScore (int index, int score)
{
  this->score[index] = score;
}

int test::getScore (int index) const
{
  return this->score[index];
}

// sport

void sport::setScore(int index, int score)
{
  this->score[index] = score;
}

int sport::getScore (int index) const
{
  return this->score[index];
}

// evaluation

void evaluation::setScore (int typeOfScore, int index, int score)
{
  if (typeOfScore == 0)
    test::setScore(index, score);
  else
    sport::setScore(index, score);
}

int evaluation::getScore (int typeOfScore, int index) const
{
  if (typeOfScore == 0)
    return test::getScore(index);
  else
    return sport::getScore(index);
}

double evaluation::calculateScore() const
{
  double sum = 0;
  for (int i = 0; i < 5; i++)
  {
    sum += test::getScore(i);
  }
  sum /= 5;
  for (int i = 0; i < 5; i++)
  {
    sum += sport::getScore(i) * 5;
  }
  return sum >= 100 ? 100 : sum;
}

// student

student::student()
{
  name = NULL;
  id = 0;
}

student::~student()
{
  if (name != NULL)
    delete[] name;
}

void student::setStudent (char *name, int id)
{
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
  this->id = id;
}

void student::setTestScore (int index, int score)
{
  evaluations.setScore(0, index, score);
}

void student::setSportScore (int index, int score)
{
  evaluations.setScore(1, index, score);
}

char *student::getName() const
{
  return name;
}

int student::getId() const
{
  return id;
}

double student::calculateScore() const
{
  return evaluations.calculateScore();
}

// school

school::school (char *filename)
{
  ifstream myFile(filename);
  if (!myFile.is_open())
  {
    cout << "Error opening file: " << filename << endl;
    exit(1);
  }
  myFile >> studentCount;
  students = new student[studentCount];
  for (int i = 0; i < studentCount; i++)
  {
    char name[20];
    int id;
    myFile >> id >> name;
    students[i].setStudent(name, id);
    for (int j = 0; j < 10; j++)
    {
      int score;
      myFile >> score;
      if (j < 5)
        students[i].setTestScore(j, score);
      else
        students[i].setSportScore(j - 5, score);
    }
  }
  myFile.close();
}

void school::report (char *fileName) const
{
  ofstream myFile(fileName);
  if (!myFile.is_open())
  {
    cout << "Error opening file: " << fileName << endl;
    exit(1);
  }
  double sum = 0;
  for (int i = 0; i < studentCount; i++)
  {
    double score = students[i].calculateScore();
    myFile << students[i].getName() << " " << students[i].getId() << " " << score << endl;
    sum += score;
  }
  myFile << "Average: " << sum / studentCount << endl;
  myFile.close();
}

