//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 4
#include "ListNode.h"
#include<iostream>
using namespace std;
template<class t>
class DoubleList{
  public:
    ListNode<t> *front;
    ListNode<t> *back;
    unsigned int size;
    DoubleList();
    void insertFront(t data);
    void insertBack(t *data);
    int find(t pos);
    ListNode<t> *remove(t data);
    t* removeFront();
    void deletePos(int pos);

    void printList();
    bool isEmpty();
    bool isFull();
    unsigned int getSize();
};

template<class t>
DoubleList<t>::DoubleList()
{
  front = NULL;
  back = NULL;
  size = 0;
}

template<class t>
void DoubleList<t>::insertFront(t data)
{
  ListNode<t> *node = new ListNode<t>(data);
  if(size==0)
  {
    back = node;
  }
  else
  {
    node->next = front;
    node->previous = node;
  }
  front = node;
  ++size;
}

template<class t>
void DoubleList<t>::insertBack(t *data)
{
  ListNode<t> *node = new ListNode<t>(data);
  if(front == NULL)
  {
    front = back;
  }
  else
  {
    back->next = node;
    node->previous = back;
  }
  back = node;
  ++size;
}

template<class t>
t* DoubleList<t>::removeFront()
{
  ListNode<t> *node = front;
  if(front->next==0)
  {
    back = 0;
  }
  else
  {
    front->next->previous=0;
  }
  front = front->next;
  --size;
  node->next = 0;
  t* tem = node->data;
  delete node;
  return tem;
}


template<class t>
ListNode<t> *DoubleList<t>::remove(t data)
{
  ListNode<t> *curr = front;
  while(curr->data != data)
  {
    curr = curr->next;
    if(curr=NULL)
    {
      return NULL;
    }
  }
  if(curr==front)
  {
    front=curr->next;
  }
  else
  {
    curr->previous->next = curr->next;
  }
  if(curr==back)
  {
    back = curr->previous;
  }
  else
  {
    curr->next->previous = curr->previous;
  }
  curr->next = NULL;
  curr->previous = NULL;
  size--;
  return curr;
}

template<class t>
void DoubleList<t>::deletePos(int pos)
{
  ListNode<t> *curNode = front;
  int count = 0;
  for(int i = 0;i<pos&&curNode!=NULL;i++)
  {
    curNode = curNode->next;
  }
  remove(curNode);
}

template<class t>
int DoubleList<t>::find(t pos)
{
  int posi = -1;
  ListNode<t> *curr = front;
  while(curr!=NULL)
  {
    posi++;
    if(curr->data==pos)
    {
      break;
    }
    else
    {
      curr=curr->next;
    }
  }
  return posi;
}
template<class t>
void DoubleList<t>::printList()
{
  ListNode<t> *curr = front;
  while(curr!=NULL)
  {
    cout<<curr->data<<endl;
    curr = curr->next;
  }
}

template<class t>
bool DoubleList<t>::isEmpty()
{
  return(size==0);
}

template<class t>
unsigned DoubleList<t>::getSize()
{
  return size;
}
