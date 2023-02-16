/*
 * This program creates a node list of students that stores their name, id, and gpa.
 * Author: Paige Wiley
 * Date: 1-27-2023
 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <time.h>
#include <fstream>
#include "Hash.h"
#include <vector>

using namespace std;

void add(Hash*& current, Node* newNode);
void deleteStudent(Hash*& current, int id);
void print(Hash* current);
bool checkRehash(Hash* current);



int main(){
  bool running = true;
  Hash* initialHash = new Hash(100);
  Hash* current = initialHash;
  vector<Node*> nodeList;

  int getId = 1;
  
  char* line = new char[100];
  char firstNameArr[100];
  vector<char*> firstNames;
  ifstream firstFile("firstName.txt");
  if(firstFile.is_open()){
    while(firstFile >> firstNameArr){
      line = new char[100];
      strcpy(line, firstNameArr);
      firstNames.push_back(line);
    }
    firstFile.close();
  }else{
    cout << "File could not be open!" << endl;
  }

  char lastNameArr[100];
  vector<char*> lastNames;
  ifstream lastFile("lastName.txt");
  if(lastFile.is_open()){
    while(lastFile >> lastNameArr){
      line = new char[100];
      strcpy(line, lastNameArr);
      lastNames.push_back(line);
    }
    lastFile.close();
  }else{
    cout << "File could not be open!" << endl;
  }

  
  while(running){
    //read in user input
    char input[10];
    cout << "Enter a command: (ADD, PRINT, DELETE, AVERAGE, QUIT)" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');

    if(strcmp(input, "ADD") == 0){//user wants to add
      Student* newStudent = new Student();

      
      //get name
      char name[20];
      cout << "What is the student's first name?" << endl;
      cin.get(name, 20);
      cin.ignore(20, '\n');
      newStudent->setName(name);

      char last[20];
      cout << "What is the student's last name?" << endl;
      cin.get(last, 20);
      cin.ignore(20, '\n');
      newStudent->setLast(last);
      

      /*
      //first name  
      int randomNumFirst = rand() % 28 + 1;
      char* firstNameGet = firstNames.at(randomNumFirst);
      char firstNameFinal[100];
      strcpy(firstNameFinal, firstNameGet);
      cout << firstNameFinal << endl;
      newStudent->setName(firstNameFinal);

      //last name
      int randomNumLast = rand() % 12 + 1;
      char* lastNameGet = lastNames.at(randomNumLast);
      char lastNameFinal[100];
      strcpy(lastNameFinal, lastNameGet);
      cout << lastNameFinal << endl;
      newStudent->setLast(lastNameFinal);
      
      
      //get ID:
      newStudent->setId(getId);
      getId++;
      */

      cout << "what is there id" << endl;
      int getId;
      cin >> getId;
      cin.ignore(20, '\n');
      newStudent->setId(getId);
      
      //get GPA:
      srand(time(NULL));
      int randInt = (rand() % 400);
      float randNum = (float)(randInt) / 100;
      cout << randNum << endl;
      float gpa = round(randNum * 100) / 100;
      cout << "GPA: " << gpa << endl;
      newStudent->setGpa(gpa);

     
    
      Node* newNode = new Node(newStudent);
      cout << newNode->getStudent()->getId() << endl;
      nodeList.push_back(newNode); //add node to node list
      add(current, newNode);

    }else if(strcmp(input, "PRINT") == 0){//print the list
      print(current);
    }else if(strcmp(input, "DELETE") == 0){//delete a node/student
      int id = 0;
      cout << "What is the ID number?" << endl;
      cin >> id;
      cin.ignore(20, '\n');
      cout << id << endl;
      deleteStudent(current, id);
      
    }else if(strcmp(input, "QUIT") == 0){//quit the program
      running = false;
    }
    //check for too  many elements
    if(checkRehash(current)){//if it needs to be rehashed
      //find new size:
      int size = current->getSize() * 2;

      //delte initial hash:
      for(int i = 0; i < initialHash->getSize(); i++){
	initialHash->resetNodes(i, NULL);
      }
      delete initialHash;
      current = new Hash(size);
  
      //input nodes again:
      vector<Node*>::iterator ptr;
      for(ptr = nodeList.begin(); ptr < nodeList.end(); ptr++){
	cout << "adding" << endl;
	cout << (*ptr)->getStudent()->getName() << endl;
	add(current, *ptr);
      }
      
      cout << "REHASHING..." << endl;
      
    }
  }

  return 0;
}

void deleteStudent(Hash*& current, int id){
  cout << "id" << id << " " << current->hashFunction(id) << endl;
  current->deleteNode(id, current->hashFunction(id), NULL, NULL);
  
}


bool checkRehash(Hash* current){
  for(int i = 0; i < current->getSize(); i++){
    if(current->mustRehash(i)){
      return true;
    }
  }
  return false;
}

void add(Hash*& current, Node* newNode){
  int key = current->hashFunction(newNode->getStudent()->getId());
  current->addData(newNode, key);
}



void print(Hash* current){
  for(int i = 0; i < current->getSize(); i++){
    current->printHash(i, NULL);
  }
  
}






