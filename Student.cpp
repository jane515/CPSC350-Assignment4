//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 4
#include "Student.h"

Student::Student()
{
  m_arrive = 0;
  m_wait = 0;
  m_timeNeed = 0;

}

Student::Student(int arrive, int timeNeed)
{
  m_arrive = arrive;
  m_timeNeed = timeNeed;
}

int Student::getArriveTime()
{
  return m_arrive;
}
int Student::getWaitTime()
{
  return m_wait;
}
int Student::getNeedTime()
{
  return m_timeNeed;
}
void Student::incrementTime()
{
  m_wait++;
}
