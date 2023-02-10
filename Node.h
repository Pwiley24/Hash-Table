#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"

using namespace std;

class Node{
 public:
  Node();
  Node(Student* student);
  ~Node();
  void setStudent(Student* newVal); //Sets the value of a node to a student
  Student* getStudent(); //Returns the value of a student found in a node
  void setNext(Node* newNext); //Sets the next node
  Node* getNext(); //Returns the next node(end of list if NULL)
  
 private:
  //Node values:
  Student* student;
  Node* next;
};





#endif
