#include <iostream>
#include <string>
#include "student.h"

student::Student::Student(string studentId, string name, int score, int time)
{
  this->studentId = studentId;
  this->name = name;
  this->score = score;
  this->time = time;
}


student::Student::~Student()
{
  delete(this);
}

string student::Student::getStudentId()
{
  return studentId;
}

string student::Student::getName()
{
  return name;
}

int student::Student::getScore()
{
  return score;
}

int student::Student::getTime()
{
  return time;
}

