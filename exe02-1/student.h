#include <string>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

namespace student
{
  class Student
  {
  public:
    Student(string studentId, string name, int score, int time);
    string getStudentId();
    string getName();
    int getScore();
    int getTime();
    ~Student();
  private:
    string studentId;
    string name;
    int score;
    int time;
  };
}

#endif // STUDENT_H

