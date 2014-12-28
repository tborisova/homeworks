#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;
#include "linked_list_two_links.cpp"

//a
int sum(DLList<int>& list){
  list.iterStart();
  list.iterEnd();
  int res = 0;
  int n = list.length() /2;
  elem_link2<int> *p = list.iterNext(), *q = list.iterPrev();

  for(int i=1;i <=n;i++){
    res += p->inf*q->inf;
    p = list.iterNext();
    q = list.iterPrev();
  }

  return res;
}

//b
int minmax(DLList<int>& list){
  list.iterStart();
  list.iterEnd();
  int max, min;
  int n = list.length()/2;
  elem_link2<int> *p = list.iterNext(), *q = list.iterPrev();
  if(p->inf < q->inf) max = p->inf;
  else max = q->inf;

  for(int i=1;i<=n-1;i++){
    p = list.iterNext();
    q = list.iterPrev();
    if(p->inf < q->inf) min = p->inf;
    else min = q->inf;
    if(min > max) max = min;
  }

  return max;
}

int min_element_of_list(DLList<int>& list){
  list.iterStart();
  elem_link2<int> *p = list.iterNext();
  int min = p->inf;

  do{
    p = list.iterNext();
    if(p && min > p->inf) min = p->inf;
  }while(p);

  return min;
}

//v
int global_minmax(DLList<int>& list){
  list.iterStart();
  list.iterEnd();
  elem_link2<int> *p = list.iterNext(), *q = list.iterPrev();
  DLList<int> l2, l3;
  int n = list.length()/2;

  for(int i = 1; i<=n; i++){
    l2.toEnd(p->inf);
    l3.toEnd(q->inf);
    p = list.iterNext();
    q = list.iterPrev();
  }

  int min_rigth = min_element_of_list(l2), min_left = min_element_of_list(l3);
  if(min_rigth > min_left) return min_rigth;
  else return min_left;
}

int main(){
  DLList<int> l1;

  l1.toStart(1);
  l1.toStart(2);
  l1.toStart(3);
  l1.toStart(4);
  l1.toStart(5);
  l1.toStart(6);

  l1.print();

  cout << global_minmax(l1) << endl;
}