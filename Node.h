#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"

using namespace std;

class Node{
    public:
        Node(Student* newStudent);
        ~Node();
        void setStudent(Student* newStudent);
        Student* getStudent();
        void setNext(Node* newNode);
        Node* getNext();
        void setLast(Node* newNode);
        Node* getLast();
    private:
        Student* student;
        Node* next;
        Node* last;
};
#endif


