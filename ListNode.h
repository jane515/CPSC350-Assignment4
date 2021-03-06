//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 4
using namespace std;
#include<cstddef>
template<class t>
class ListNode
{
  public:
    ListNode();
    ListNode(t *d);
    ~ListNode();
    t *data;
    ListNode<t> *next;
    ListNode<t> *previous;
};
template<class t>
ListNode<t>::ListNode()
{
  data = NULL;
  next = NULL;
  previous = NULL;
}
template<class t>
ListNode<t>::ListNode(t *d)
{
  data =d;
  next = NULL;
  previous = NULL;
}

template<class t>
ListNode<t>::~ListNode()
{
  if(next != NULL)
  {
    next = NULL;
    previous = NULL;
    delete next;
    delete previous;
  }
}
