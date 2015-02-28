#include <iostream>
#include <cassert>
using namespace std;
#include "linked_list_one_link.cpp"

int main(){
  LList<int> l1, l2;

  int i;

  for(i=1;i<=5;i++){
    l1.toEnd(i);
  }

  for(i=6;i<=8;i++){
    l2.toEnd(i);
  }

  LList<int> l3 = l1;

  l1.print();
  l2.print();
  l3.print();
  
  l1.reverse();
  l2.reverse();
  l3.reverse();
  
  l1.print();
  l2.print();
  l3.print();
  
  LList<int> l4 = l1;
  l4.concat(l2);
  l4.concat(l3);
  l4.print();
}