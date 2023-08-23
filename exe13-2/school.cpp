#include <iostream>
#include <fstream>
#include <string>
#include <map>
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
  name = "";
  id = 0;
}

void student::setStudent (string name, int id)
{
  this->name = name;
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

string student::getName() const
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
  for (int i = 0; i < studentCount; i++)
  {
    string name;
    int id;
    myFile >> id >> name;
    students[id] = new student;
    students[id]->setStudent(name, id);
    for (int j = 0; j < 10; j++)
    {
      int score;
      myFile >> score;
      if (j < 5)
        students[id]->setTestScore(j, score);
      else
        students[id]->setSportScore(j - 5, score);
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
  for (auto i = students.begin(); i != students.end(); i++)
    myFile << "ID: " << i->first << "\tname: " << i->second->getName() << "\tscore: " << i->second->calculateScore() << endl;
  myFile.close();
}

