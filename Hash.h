#ifndef HASH_H
#define HASH_H
#include "Node.h"
#include <iostream>

using namespace std;

class Hash{
public:

  Hash(int capacity);

  int getSize();
  
  int hashFunction(int data);

  void addData(Node* data, int key);

  void addNode(Node* data, Node* next, int slot);

  void printHash(int slot, Node* current);

  void deleteNode(int id, int slot, Node* current, Node* previous);
  
  bool mustRehash(int slot);

  void resetNodes(int slot, Node* current);
  
  int key;
  int tableSize;
  int elements;
  Node** table;

};
#endif
