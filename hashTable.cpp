/*
 * This program creates a node list of students that stores their name, id, and gpa.
 * Author: Paige Wiley
 * Date: 1-27-2023
 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <time.h>
#include "Hash.h"

using namespace std;

void add(Hash* current, Node* newNode);
void print(Hash* current);



int main(){
  bool running = true;
  Hash* current = new Hash(100);

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
    
      //get ID:
      int id = 0;
      cout << "What is the student's ID?" << endl;
      cin >> id;
      cin.ignore(20, '\n');
      newStudent->setId(id);

      //get GPA:
      srand(time(NULL));
      int randInt = (rand() % 400);
      float randNum = (float)(randInt) / 100;
      cout << randNum << endl;
      float gpa = round(randNum * 100) / 100;
      cout << "GPA: " << gpa << endl;
      newStudent->setGpa(gpa);

     
  
      Node* newNode = new Node(newStudent);
      add(current, newNode);

    }else if(strcmp(input, "PRINT") == 0){//print the list

    }else if(strcmp(input, "DELETE") == 0){//delete a node/student

      
    }else if(strcmp(input, "QUIT") == 0){//quit the program
      running = false;
    }
  }

  return 0;
}

void add(Hash* current, Node* newNode){
  int key = current->hashFunction(newNode->getStudent()->getId());
  current->addData(newNode, key);
}



void print(Hash* current){
  
}






