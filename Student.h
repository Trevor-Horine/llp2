/*this is the header for student class
 *Trevor Horine
 *12/11/2017
 */
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;

class Student{
 public:
  Student(char* newnamef, char* newnamel, int newid, float newgpa);
  char* getnamef();
  char* getnamel();
  int getid();
  float getgpa();
 private:
  char* namef;
  char* namel;
  int id;
  float gpa;
};
#endif
