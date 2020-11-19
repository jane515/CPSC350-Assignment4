//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 4
#include "GenQueue.h"
#include "Student.h"
#include <iostream>
#include <sstream>
#include<fstream>
#include<algorithm>
using namespace std;
class Simulation
{
  public:
    Simulation();
    void readFile(string input);
    void run();

    int totalStudents;
    int numWindow;
    int timeTick;
    int timeNeed;
    int numStudent;
    int totalWindowIdleTime;
    int longestWindowIdleTime;
    int totalWaitTime;

    double mean;
    double medianWait;
    double longestWait;
    int waitOver10;
    double meanIdle;
    double longestIdle;
    int idleOver5;

    double getMean();
    double getMedian();
    double getLongestWait();
    int getWaitOver10();
    double getMeanIdle();
    double getLongestIdle();
    int getIdleOver5();

    int *openWindow;
    int *openWindowIdleTime;
    int *waitTimeArray;
    GenQueue<Student> *studentQueue;

    //GenQueue<Student> *studentQueue = new GenQueue<Student>();
};
