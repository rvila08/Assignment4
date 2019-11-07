#include "statsTracker.h"
#include <bits/stdc++.h>

using namespace std;

//Constructor
//Tracking the idle data, student data, and size of the array
statsTracker::statsTracker(int* i2,int* i,int size, int windowSize){
  idleData = i;
  studentData = i2;
  arrSize = size;
  windowS = windowSize;
}

//Destructor
statsTracker::~statsTracker(){

}

//Method to find the mean of the array
double statsTracker::findMean(){
  int sum = 0;
  for(int i=0;i<arrSize;++i){
    sum+= studentData[i];
  }
  double mean = (double)sum/(double)arrSize;
  cout << "The mean student wait time: " << mean << endl;
  return mean;
}

//Method to find the idle median of the array
int statsTracker::findIdleMax(){
  int max = 0;
  for(int i=0;i<windowS;++i){
    if(idleData[i] > max){
      max = idleData[i];
    }
  }
  cout << "The longest window idle time: " << max << endl;
  return max;
}

//Method to find the maximum of the array
int statsTracker::findMax(){
  int max = 0;
  for(int i=0;i<arrSize;++i){
    if(studentData[i] > max){
      max = studentData[i];
    }
  }
  cout << "The longest student wait time: " << max << endl;
  return max;
}

//Method to find how many students wait over 10 minutes
int statsTracker::over10(){
  int over10 = 0;
  for(int i=0;i<arrSize;++i){
    if(studentData[i] > 10){
      over10++;
    }
  }
  cout << "Students Who Wait Over 10 Minutes: " << over10 << endl;
  return over10;
}

//Method to find the idle mean of the array
double statsTracker::findIdleMean(){
  int sum = 0;
  for(int i=0;i<windowS;++i){
    sum+= idleData[i];
  }
  double mean = (double)sum/(double)windowS;
  cout << "The mean window idle time: " << mean << endl;
  return mean;
}

//Method to find how many windows are idle for over 5 minutes
int statsTracker::idleOver5(){
  int over5 = 0;
  for(int i=0;i<windowS;++i){
    if(idleData[i] > 5){
      over5++;
    }
  }
  cout << "Windows Idle Over 5 minutes: " << over5 << endl;
  return over5;
}

//Method to find the median of the array
int statsTracker::findMedian(){

  sort(studentData, studentData + arrSize);
  if(arrSize%2 != 0)
    return (int)studentData[arrSize/2];

  return (int) (studentData[(arrSize-1)/2] + studentData[arrSize/2]) / 2;
}
