#ifndef Window_H
#define Window_H
#include <iostream>
#include "Student.h"

using namespace std;

class Window{
public:
  Window();
  ~Window();
  void studentArrived(Student *s, int currentTime);
  void adjustTime();
  bool isStudentLeave();
  bool isStudentHere();
  void storeStudents(Student *s);
  bool allWindowsEmpty();
  Student* exitStudent();
  int studentCounter = 0;
  bool open;
  unsigned int currTime;
  int idleTime;
  int timeWithStudent;
  Student *studentHere;
};
#endif
