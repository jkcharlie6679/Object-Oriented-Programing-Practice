#ifndef SCHOOL_H
#define SCHOOL_H

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
  char *name;
  int id;
  evaluation evaluations;
public:
  student();
  ~student();
  void setStudent(char *, int);
  void setTestScore(int, int);
  void setSportScore(int, int);
  char *getName() const;
  int getId() const;
  double calculateScore() const;
};

class school
{
protected:
  student *students;
  int studentCount;
public:
  school(char *);
  void report(char *) const;
};

#endif // SCHOOL_H

