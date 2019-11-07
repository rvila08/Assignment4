#ifndef statsTracker_H
#define statsTracker_H
#include "Registrar.h"
#include "Window.h"

class statsTracker{
public:
  statsTracker(int* i2,int* i,int size);
  ~statsTracker();
  double findMean();
  int findIdleMax();
  int findMax();
  int over10();
  double findIdleMean();
  int idleOver5();
  int findMedian();
private:
  int* idleData;
  int* studentData;
  int arrSize;
};
#endif
