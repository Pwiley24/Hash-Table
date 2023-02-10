#include <iostream>
#include <cstring>
#include "Student.h"
#include <cmath>

using namespace std;

Student::Student(){
  name = new char[30];
  id = 0;
  gpa = 0;
}

char* Student::getName(){
  return name;
}

char* Student::getLast(){
  return last;
}

int Student::getId(){
  return id;

}

void Student::setName(char* title){
  name = new char[30];
  strcpy(name, title);
}

void Student::setLast(char* title){
  last = new char[30];
  strcpy(last, title);
}

void Student::setId(int number){
  id = number;
}

void Student::setGpa(float number){
  /*
   *I used code from java2blog.com
   *I used this code to round a float to two decimal places
   *URL: https://java2blog.com/round-to-2-decimal-places-cpp/
   */
  gpa = ceil(number * 100) / 100;
}

float Student::getGpa(){
  return gpa;
}
