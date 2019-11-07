#include "LinkListQueue.h"
#include "DubLinkedList.h"
#include "Registrar.h"
#include "statsTracker.h"

int main(int argc, char const *argv[]) {

  string fileName = "";
  if(argc == 2){
    fileName = argv[1];
  }
  else{
    cout << "Wrong user input" << endl;
    exit(0);
  }

  Registrar *r = new Registrar();
  r->fillQueue(fileName);
  while(r->allWindowsEmpty()){ //Add check to see if windows are empty too
    r->timeStep();
  }
  statsTracker *s = new statsTracker(r->completedStudents,r->idleArr,r->totalStudents,r->windowsOpen);
  s->findMean();
  s->findMax();
  cout << "The median student wait time: " << s->findMedian() << endl;
  s->findIdleMean();
  s->findIdleMax();
  s->idleOver5();
  s->over10();

}
