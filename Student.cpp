/* this is the student class
 *Trevor Horine
 *12/11/2017
 */

#include "Student.h"
Student::Student(char* newnamef, char* newnamel, int newid, float newgpa){
  namef = newnamef;
  namel = newnamel;
  id = newid;
  gpa = newgpa;
}
//method to get first name
char* Student::getnamef(){
  return namef;
}
//method tp get last name
char* Student::getnamel(){
  return namel;
}
//mehtod to get id
int Student::getid(){
  return id;
}
//mehtod to get gpa
float Student::getgpa(){
  return gpa;
}
