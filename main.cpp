/*this is a simple linked list program
 *Trevor Horine
 *12/11/2017
 */

#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"
#include <iomanip>

using namespace std;

Student* getin();
void add(Node* current, Student* newvalue);
void print(Node* next);
Node* remove(int re, Node* next);
void up(char* in);
void average(int count, float ave, Node* next);

Node* head = NULL;
//main method
int main(){
  char* action = new char[20];
  float ave = 0;
  int count = 0;
  int re;
  bool playing = true;
  while(playing == true){
    cout << "Do you want to add, list, delete, average, or quit?" << endl;
    cin >> action;
    up(action);
    if(strcmp(action, "ADD") == 0){
      Student* s =getin();
      add(head,s);
    }
    if(strcmp(action, "LIST") == 0){
      print(head);
    }
    if(strcmp(action, "DELETE") == 0){
      head = remove(re, head);
    }
    if(strcmp(action, "AVERAGE") == 0){
      average(count, ave, head);
    }
    if(strcmp(action, "QUIT") == 0){
      playing = false;
    }
  }
}
//read in info
Student* getin(){
  char* first = new char[100];
  char* last = new char[100];
  int id;
  float gpa;
  cout << "What is the students first name?" << endl;
  cin >> first;
  cout << "What is the students last name?" << endl;
  cin >> last;
  cout << "what is the students id number?" << endl;
  cin >> id;
  cout << "What is the students gpa?" << endl;
  cin >> gpa;
  Student* s = new Student(first, last, id, gpa);
  return s;
}
//add node to ll
void add(Node* current, Student* newvalue){
  if(current == NULL){
    Node* temp = head;
    cout << "head"<< endl;
    head = new Node(newvalue);
    head -> setStudent(newvalue);
    head -> setNext(temp);
  }
  else{
    if(current -> getStudent() -> getid() > newvalue -> getid()){
      add(current -> getNext(), newvalue);
    }
    else{
      current -> setNext(new Node(newvalue));
      current = current -> getNext();
      current -> setNext(current -> getNext());
    }
  }
}
//print ll
void print(Node* next){
  if(next == head){
    cout << "Students: " <<endl;
  }
  if(next != NULL){
    cout <<"Name: " << next -> getStudent() -> getnamef() << " " << next -> getStudent() -> getnamel() << " ID: " << next -> getStudent() -> getid() << " GPA: " << fixed << setprecision(2) << next -> getStudent() -> getgpa() << endl;
    print(next -> getNext());
  }
}
 void up(char* in){
   for(int i = 0; i < 100; i++){
     in[i] = toupper(in[i]);
   }
 }
//average method
void average(int count, float ave, Node* next){
  if(next == NULL){
    cout << fixed << setprecision(2) << ave/count << endl;
  }
  else{
    ave =  ave + next -> getStudent() -> getgpa();
    count++;
    average(count, ave, next -> getNext());
  }
}
//remove method
Node* remove(int re, Node* head){
  cout << "What is the id number of the student you want to remove?" << endl;
  cin >> re;
  Node* hold = head;
  Node* current = head;
  if(current -> getStudent() -> getid() == re){
    Node* temp = current;
    current = current -> getNext();
    delete temp;
    return current;
  }
  if(current -> getNext() -> getStudent() -> getid() == re){
    Node* temp = current;
    current = current -> getNext();
    temp -> setNext(current -> getNext());
    delete current;
    current = temp -> getNext();
    return hold;
  }
  else{
    remove(re, current -> getNext());
  }
}
