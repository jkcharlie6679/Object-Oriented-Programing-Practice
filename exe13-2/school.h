#ifndef SCHOOL_H
#define SCHOOL_H

#include <string>
#include <map>

using namespace std;

class Score
{
protected:
  int score[5];
};

class test : public Score
{
public:
  void setScore(int, int);
  int getScore(int) const;
};

class sport : public Score
{
public:
  void setScore(int, int);
  int getScore(int) const;
}; 

class evaluation : public test, public sport
{
public:
  void setScore(int, int, int);
  int getScore(int, int) const;
  double calculateScore() const;
};

class student 
{
private:
  string name;
  int id;
  evaluation evaluations;
public:
  student();
  void setStudent(string, int);
  void setTestScore(int, int);
  void setSportScore(int, int);
  string getName() const;
  int getId() const;
  double calculateScore() const;
};

class school
{
protected:
  map<int, student*> students;
  // student *students;
  int studentCount;
public:
  school(char *);
  void report(char *) const;
};

#endif // SCHOOL_H

