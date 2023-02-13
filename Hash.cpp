#include <iostream>
#include "Hash.h"

using namespace std;

Hash::Hash(int capacity){
  tableSize = capacity;
  table = new Node*[capacity];
  elements = 0;
  
}

int Hash::hashFunction(int data){
  //divide size by id number
  key = data % tableSize;
  return key;
}

void Hash::addData(Node* data, int key){
  for(int i = 0; i < tableSize; i++){
    if(key == i){
      //get next node
      Node* next = new Node(NULL);
      if(table[i] != NULL){
	next = table[i]->getNext();
      }else {
	next = NULL;
      }
      addNode(data, next, i); //add the node if it is in the right slot
    }
  }
}

void Hash::addNode(Node* data, Node* next, int slot){
  if(table[slot] == NULL){//no nodes in list
    table[slot] = data;
  }else{ //already nodes in list
    table[slot]->setNext(data);
    data->setNext(next);
  }


  
  //if slot in table is NULL add node
  //if slot has more nodes recurse through
  //keep track of recursions (more than three)
  //when it gets to NULL next 
}


void Hash::printHash(int slot, Node* current){
  if(table[slot] != NULL){//there are nodes to print
    if(current == NULL){//first print
      current = table[slot];
      cout << table[slot]->getStudent()->getId() << ", " << table[slot]->getStudent()->getName() << endl;
    }else {
      cout << current->getStudent()->getId() << ", " << current->getStudent()->getName() << endl;
    }
    cout << current->getNext()->getStudent()->getName() << endl;
    if(current->getNext() != NULL){//more nodes to print
      current = current->getNext();
      printHash(slot, current);
    }
  }
}

int Hash::getSize(){
  return tableSize;
}

bool Hash::mustRehash(int slot){
  if(table[slot] != NULL &&
     table[slot]->getNext() != NULL &&
     table[slot]->getNext()->getNext() != NULL){//three elements
    return true;
  }
  return false;
}
