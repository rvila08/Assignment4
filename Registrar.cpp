
#include "Registrar.h"


using namespace std;

//Constructor
Registrar::Registrar(){
  windowsOpen = 0;
  arrivalTime = 0;
  numStudents = -1;
  studentQ = new LinkListQueue<Student*>();
}

//Destructor
Registrar::~Registrar(){

}

//Method to fill the queue of students
void Registrar::fillQueue(string fileName){

  //Access the file given by user
  string line = "";
  int lineCount = 0;
  fileStream.open(fileName);

  if(fileStream.good()){
    while(getline(fileStream, line)){
      //Going through the windows open in file
      if (lineCount == 0){
        windowsOpen = stoi(line);
        lineCount++;
        continue;
      }
      //Going through the arrival time given in file
      if (lineCount == 1){
        arrivalTime = stoi(line);
        lineCount++;
        continue;
      }
      //Going through the number of students given in file
      if (lineCount == 2){

        numStudents = stoi(line);
        lineCount = -1;
        continue;
      }
      //Inserting the students into the queue
      if (numStudents>0){
        newStudent = new Student(stoi(line),arrivalTime);
        studentQ->insert(newStudent);
        totalStudents++;
        numStudents--;
      }
      //Resets the variable lineCount to read arrival time
      if(numStudents == 0){
        lineCount = 1;
      }
    }
  }
  //Creating windows array
  windowArr = new Window*[windowsOpen];
  for(int i=0;i<windowsOpen;++i){
    Window *newWindow = new Window();
    windowArr[i] = newWindow;
  }
  completedStudents = new int[totalStudents];
  idleArr = new int[totalStudents];
}

//Method to fill the windows with students
void Registrar::fillWindows(){
  //empty queue fill window
  for(int i = 0;i<windowsOpen;++i){
    if(getQueue()->isEmpty()){
      break;
    }
    double studentTime = studentQ->peek()->timeArrived;
    double currHour = (double)currTime/60;
    if(windowArr[i]->open == true && currHour >= studentTime){
      Student* st = studentQ->remove();
      windowArr[i]->studentArrived(st,currTime); //remove from the queue and put at the window

    }
  }
}

//Method to increment the time
void Registrar::timeStep(){
  for(int i =0;i<windowsOpen;++i){
    windowArr[i]->adjustTime();
  }
currTime++;
  for(int i =0;i<windowsOpen;++i){
    if(windowArr[i]->isStudentLeave()){
      Student* studentLeft = windowArr[i]->exitStudent();
      storeData(studentLeft, windowArr[i]);

    }
  }
  fillWindows();
}

//Getting the queue of students
LinkListQueue<Student*>* Registrar::getQueue(){
  return studentQ;
}

//Storing the completed students into an array
void Registrar::storeData(Student *s, Window *&w){
  idleArr[studentCounter] = w->idleTime;
  w->idleTime = 0;
  completedStudents[studentCounter++] = s->timeLeftWindow - s->timeArrived ;
}

bool Registrar::allWindowsEmpty(){
  for(int i=0;i<windowsOpen;++i){
    if(windowArr[i]->open == false){
      return true;
    }
    else if(!studentQ->isEmpty()){
      return true;
    }
  }
  return false;
}
