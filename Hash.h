#ifndef HASH_H
#define HASH_H
#include "Node.h"
#include <iostream>

using namespace std;

class Hash{
public:

  Hash(int capacity);
  
  int hashFunction(int data);

  void addData(Node* data, int key);

  void addNode(Node* data, Node* next, int slot);

  void printHash(int slot);

private:
  int key;
  
  int tableSize;
  int elements;
  Node** table;

};
#endif
