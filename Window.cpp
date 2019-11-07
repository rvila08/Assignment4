#include "Window.h"

using namespace std;

//Constructor
Window::Window(){
  this->open = true;
  this->idleTime = 0;
  this->studentHere = nullptr;
}

//Destructor
Window::~Window(){

}

//Method to check if the student has arrived at the window
void Window::studentArrived(Student *s, int currentTime){
  s->timeArrived = currentTime;
  s->atWindow = true;
  studentHere = s;
  open = false;

}

//Method to change window variables
void Window::adjustTime(){
  if(open == true){
    idleTime++;
  }
  else{
    timeWithStudent++;
  }
  currTime++;
}

//Boolean to check whether the student has left the window
bool Window::isStudentLeave(){
  if(open == true){
    return false;
  }
  if(isStudentHere() == true && studentHere->windowTime == timeWithStudent){
    return true;
  }
  return false;
}

//Method to update student variables
Student* Window::exitStudent(){
  Student* thisStudent = studentHere;
  thisStudent->timeLeftWindow = currTime;


  thisStudent = nullptr;
  timeWithStudent = 0;
  open = true;

  return studentHere;
}

//used this function because it was giving me an error when i called studentHere->windowTime
//prevent from accessing nullptr
//Boolean to check whether student is at the window
bool Window::isStudentHere(){
  if(studentHere == nullptr){
    return false;
  }
  return true;
}
