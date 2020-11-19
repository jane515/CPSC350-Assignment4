//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 4
#include "DoubleList.h"
template<class t>
class GenQueue{
public:

  int size;
  GenQueue();
  void insert(t *data);
  t* remove();
  //bool isFull();
  bool isEmpty();
  t* peek();
  unsigned int getSize();
  DoubleList<t> myQueue;
  ListNode<t> *front;
  ListNode<t> *back;
};

template<class t>
GenQueue<t>::GenQueue()
{
  DoubleList<t> myQueue;
  size = 0;
}

template<class t>
void GenQueue<t>::insert(t *data)
{
  myQueue.insertBack(data);
  size++;
}

template<class t>
t* GenQueue<t>::remove()
{
  if(myQueue.getSize()==0)
  {
    cout<<"It's empty"<<endl;
  }
  else
  {
    t* node = myQueue.removeFront();
    return node;
  }
}

template<class t>
bool GenQueue<t>::isEmpty()
{
  return (size==0);
}

template<class t>
unsigned GenQueue<t>::getSize()
{
  return size;
}

template<class t>
t* GenQueue<t>::peek()
{
  if(size==0)
  {
    cout<<"It's empty"<<endl;
  }
  return myQueue.front->data;
}
