//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 4

class Student
{
  public:
    Student();
    Student(int arrive, int timeNeed);
    int getArriveTime();
    int getWaitTime();
    int getNeedTime();
    void incrementTime();
  private:
    int m_arrive;
    int m_wait;
    int m_timeNeed;

};
