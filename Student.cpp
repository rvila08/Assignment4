#include "student.h"

using namespace std;

//Constructor
Student::Student(int waitTime, int arrivalTime){
  this->windowTime = waitTime;
  this->atWindow = false;
  this->isGone = false;
  this->timeArrived = arrivalTime;
}

//Destructor
Student::~Student(){

}
