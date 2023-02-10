#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(Student * student){
  student = student;
  next = NULL;
}
Node::~Node(){
  delete &student;
  next = NULL;
}

//Sets the value of the node to a student
void Node::setStudent(Student* newVal){
  student = newVal;
}

//Returns the value of a student found in a node
Student* Node::getStudent(){
  return student;
}

//Sets the next node
void Node::setNext(Node* newNext){
  next = newNext;
}

//Returns the next node (end of list if NULL)
Node* Node::getNext(){
  return next;
}
