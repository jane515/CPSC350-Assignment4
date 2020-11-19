//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 4
#include "Simulation.h"
using namespace std;
Simulation::Simulation()
{
  totalStudents = 0;
  numWindow = 0;
  timeTick = 0;
  timeNeed = 0;
  numStudent = 0;
  totalWindowIdleTime = 0;
  longestWindowIdleTime = 0;
  studentQueue = new GenQueue<Student>();
}

void Simulation::readFile(string input)
{
  std::ifstream file;
  file.open(input);
  if(file.is_open())
  {
    std::string line;
    getline(file,line);
    //get number of windows open
    numWindow = stoi(line);
    openWindow = new int[numWindow];
    openWindowIdleTime = new int[numWindow];
    for(int i =0;i<numWindow;i++)
    {
      openWindow[i]=0;
    }
    while(std::getline(file,line))
    {
      timeTick = stoi(line);
      getline(file,line);
      numStudent= stoi(line);
      totalStudents+=numStudent;
      for(int i =0;i<numStudent;i++)
      {
        getline(file,line);
        timeNeed = stoi(line);
        Student *student = new Student(timeTick,timeNeed);
        studentQueue->insert(student);
      }
    }
  }
  waitTimeArray = new int[totalStudents];
  for(int i=0;i<totalStudents;i++)
  {
    waitTimeArray[i]=0;
  }
}

void Simulation::run()
{
  int clock = 0;
  int windowAvailable = numWindow;
  while(true)
  {
    if(!studentQueue->isEmpty())
    {
      if(studentQueue->peek()->getArriveTime()<=clock)
      {

        if(windowAvailable>0)
        {
          for(int i =0;i<numWindow;i++)
          {
            if(openWindow[i]==0)
            {
              if(studentQueue->getSize()!=0)
              {
                if(studentQueue->peek()->getArriveTime()<=clock)
                {
                  Student* s1 = studentQueue->remove();
                  openWindow[i]=s1->getNeedTime()+1;
                  numStudent++;
                  windowAvailable--;
                  totalWaitTime +=(clock-s1->getArriveTime());
                  waitTimeArray[numStudent]=clock-s1->getArriveTime();
                }
              }
            }
            else
            {
              //not student waiting
            }
          }
        }
      }
    }
    for(int i =0;i<windowAvailable;i++)
    {
      if(openWindow[i]!=0)
      {
        openWindow[i]--;
        if(openWindow[i]==0)
        {
          windowAvailable++;
        }
      }
      else
      {
        openWindowIdleTime[i]++;
      }
    }
    clock++;
    if(studentQueue->isEmpty())
    {
      if(windowAvailable==numWindow)
      {
        break;
      }
    }
  }
}
double Simulation::getMean()
{
  mean = (double)totalWaitTime/(double)totalStudents;
  return mean;
}

double Simulation::getMedian()
{
  sort(waitTimeArray,waitTimeArray+totalStudents);
  if(totalStudents%2==1)
  {
    double m1 = (double) waitTimeArray[(totalStudents-1)/2];
    double m2 = (double) waitTimeArray[totalStudents/2];
    medianWait = (m1+m2)/2;
  }
  else
  {
    medianWait = (double)waitTimeArray[totalStudents/2];
  }
  return medianWait;
}
/*
double Simulation::getMedian()
{
  ListNode<int> *curr = waitTimeArray.front;
  int count = 0;
  while(curr!=NULL)
  {
    curr = curr->next;
    count++;
  }
  if(count>0)
  {
    waitTimeArray = new int[count];
    curr = waitTimeArray.front;
    for(int i =0;i<count;i++)
    {
      waitTimeArray[i] = curr->data;
    }
    sort(waitTimeArray,waitTimeArray+count);
    if(count%2!=0)
    {
      medianWait = (double)waitTimeArray[count/2];
    }
    else
    {
      double m1 = (double) waitTimeArray[(count-1)/2];
      double m2 = (double) waitTimeArray[count/2];
      median = (m1+m2)/2;
    }
  }
  waitTimeArrayCount = count;
  return medianWait;
}*/

//longest idle time
double Simulation::getLongestIdle()
{
  for(int i =0;i<numWindow;i++)
  {
    if(longestIdle<openWindowIdleTime[i])
    {
      longestIdle=openWindowIdleTime[i];
    }
  }
  return longestIdle;
}

//longest wait time
double Simulation::getLongestWait()
{
  sort(waitTimeArray,waitTimeArray+totalStudents);
  longestWait = waitTimeArray[sizeof(waitTimeArray)-1];
  return longestWait;
}
//idle window over 5 min
int Simulation::getIdleOver5()
{
  for(int i =0;i<numWindow;i++)
  {
    if(openWindowIdleTime[i]>5)
    {
      idleOver5++;
    }
  }
  return idleOver5;
}

//wait time over 10 min
int Simulation::getWaitOver10()
{
  for(int i = 0;i<sizeof(waitTimeArray);i++)
  {
    if(waitTimeArray[i]>10)
    {
      waitOver10++;
    }
  }
  return waitOver10;
}

//mean idle window
double Simulation::getMeanIdle()
{
  for(int i =0;i<numWindow;i++)
  {
    totalWindowIdleTime +=openWindowIdleTime[i];
    meanIdle = (double)totalWindowIdleTime/(double)numWindow;
    return meanIdle;
  }
}
