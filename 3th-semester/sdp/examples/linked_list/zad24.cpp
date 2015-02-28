#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;
#include "linked_list_two_links.cpp"

void sort(DLList<int>& l1, DLList<int>& l2){
  l1.iterStart();
  l1.iterEnd();
  elem_link2<int> *p = l1.iterNext(), *q = l1.iterPrev();
  
  while(p != q){
    if(p->inf <= q->inf){
      l2.toEnd(p->inf);
      p = l1.iterNext();
    }else{
      l2.toEnd(q->inf);
      q = l1.iterPrev();
    }
  }
  l2.toEnd(p->inf);
}

int main(){
  DLList<int> l1, l2;

  l1.toEnd(1);
  l1.toEnd(2);
  l1.toEnd(3);
  l1.toEnd(6);
  l1.toEnd(5);
  l1.toEnd(4);

  l1.print();

  sort(l1, l2);
  l2.print();
}