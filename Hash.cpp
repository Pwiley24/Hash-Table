#include <iostream>
#include "Hash.h"

using namespace std;

Hash::Hash(int capacity){
  tableSize = capacity;
  table = new Node*[capacity];
  elements = 0;
  
}

void Hash::deleteNode(int id, int slot, Node* current, Node* previous){
  cout << "id inside " << id << " " << slot << endl;
  //delete first element:
  Node* tempNode;
  if(current == NULL &&
     table[slot] != NULL){
    current = table[slot];
    cout << table[slot]->getStudent()->getId() << endl;
    tempNode = table[slot]->getNext();
    cout << tempNode << endl;
    if(table[slot]->getStudent()->getId() == id){//node to delete
      cout << "deleting first node" << endl;
      delete table[slot];
      table[slot] = tempNode;
    }else{
      deleteNode(id, slot, tempNode, table[slot]);
    }
  }else{//not element in list
    if(current->getStudent()->getId() == id){//node to delete
      previous->setNext(current->getNext());
      delete current;
    }
    if(previous->getNext() != NULL){
      deleteNode(id, slot, previous->getNext(), previous);
    }
  }
}

int Hash::hashFunction(int data){
  //divide size by id number
  key = data % tableSize;
  return key;
}

void Hash::addData(Node* data, int key){
  //get next node
  Node* next = new Node(NULL);
  if(table[key] != NULL){
     next = table[key]->getNext();
  }else {
     next = NULL;
  }
   addNode(data, next, key); //add the node if it is in the right slot
}

void Hash::addNode(Node* data, Node* next, int slot){
  if(table[slot] == NULL){//no nodes in list
    table[slot] = data;
  }else{ //already nodes in list
    table[slot]->setNext(data);
    data->setNext(next);
  }


  

}


void Hash::printHash(int slot, Node* current){
  if(table[slot] != NULL){//there are nodes to print
    if(current == NULL){//first print
      cout << "first print" << endl;
      current = table[slot];
      cout << table[slot]->getStudent()->getId() << ", " << table[slot]->getStudent()->getName() << endl;
    }else {
      cout << "not first print" << endl;
      cout << current->getStudent()->getId() << ", " << current->getStudent()->getName() << endl;
    }
    // cout << current->getNext()->getStudent()->getName() << endl;
    if(current->getNext() != NULL){//more nodes to print
      printHash(slot, current->getNext());
    }
  }
}

int Hash::getSize(){
  return tableSize;
}

void Hash::resetNodes(int slot, Node* current){
  if(current == NULL &&
     table[slot] != NULL){
    cout << table[slot]->getStudent()->getName() << endl;
    current = table[slot];
  }
  if(current != NULL){ //table[slot] wasn't null either
    Node* tempNode = current->getNext();
    current->setNext(NULL);
    if(tempNode != NULL){
      resetNodes(slot, tempNode);
    }
  }
}

bool Hash::mustRehash(int slot){
  if(table[slot] != NULL &&
     table[slot]->getNext() != NULL &&
     table[slot]->getNext()->getNext() != NULL){//three elements
    return true;
  }
  return false;
}


void Hash::resetTable(){
  for(int i = 0; i < tableSize; i++){
    table[i] == NULL;
  }
}
