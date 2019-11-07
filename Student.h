#ifndef Student_H
#define Student_H

using namespace std;

class Student{
  public:
    Student(int waitTime, int arrivalTime);
    ~Student();
    unsigned int windowTime;
    //Checks if student is at the window
    bool atWindow;
    //Checks if the student has completed
    bool isGone;
    //The window that the student arrives at
    unsigned int windowArrived;
    //The time the student arrived at the queue
    unsigned int timeArrived;
    //The time the student has left the window (completed)
    unsigned int timeLeftWindow;
};
#endif
