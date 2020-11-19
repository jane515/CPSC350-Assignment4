//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 4
#include "Simulation.h"

using namespace std;
int main(int argc, char *argv[])
{
  std::string input;
  if(argc>1)
  {
    input = argv[1];
  }
  Simulation *a4 = new Simulation();
  cout<<"The mean student wait time is: "<<a4->getMean()<<endl;
  cout<<"The median student wait time is: "<<a4->getMedian()<<endl;
  cout<<"The longest student wait time is: "<<a4->getLongestWait()<<endl;
  cout<<"The number of students wait over 10 minutes is: "<<a4->getWaitOver10()<<endl;
  cout<<"The mean idle window time is: "<<a4->getMeanIdle()<<endl;
  cout<<"The longest window idle time is: "<<a4->getLongestIdle()<<endl;
  cout<<"The number of window idle for over 5 minutes is: "<<a4->getIdleOver5()<<endl;
  return 0;
}
