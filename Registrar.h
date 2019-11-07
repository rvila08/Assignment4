#ifndef Registrar_H
#define Registrar_H

#include "Student.h"
#include "DubLinkedList.h"
#include "LinkListQueue.h"
#include "Window.h"
#include <iostream>
#include <fstream>

using namespace std;

class Registrar{
  public:
    void fillQueue(string fileName); //remove from queue and is atWindow
    void fillWindows();
    void timeStep();
    int getTotalStudents();
    LinkListQueue<Student*>* getQueue();
    void updateStudents(); //update student times
    void storeData(Student *s,Window *&w);
    bool allWindowsEmpty();
    Registrar();
    ~Registrar();
    int *completedStudents;
    int *idleArr;
    int totalStudents;
    unsigned int windowsOpen;
  private:
    unsigned int studentCounter = 0;
    unsigned int arrivalTime;
    unsigned int currTime;
    Window **windowArr;
    int numStudents;
    ifstream fileStream;
    LinkListQueue<Student*> *studentQ;
    Student *newStudent;

};
#endif
