#include <iostream>
using namespace std;
#include "sortList.cpp"

template <typename T>
void mergeList(LList<T>& l1, LList<T>& l2, LList<T>&  r){
   elem_link1<T> *l1_current, *l2_current;
   l1.iterStart();
   l1_current = l1.iter();
   l2.iterStart();
   l2_current = l2.iter();

   while(l1_current && l2_current){
    if(l1_current->inf < l2_current->inf){
      r.toEnd(l1_current->inf);
      l1_current = l1.iter();
    }else{
      r.toEnd(l2_current->inf);
      l2_current = l2.iter();
    }
   }

   if(l1_current){
      while(l1_current){
        r.toEnd(l1_current->inf);
        l1_current = l1.iter();
      }
   }

   if(l2_current){
      while(l2_current){
        r.toEnd(l2_current->inf);
        l2_current = l2.iter();
      }
   }
}

int main(){
  LList<int> l1, l2, r;

  l1.toEnd(2);
  l1.toEnd(12);
  l1.toEnd(223);
  l1.toEnd(1);
  sortList(l1);

  l2.toEnd(0);
  l2.toEnd(10);
  l2.toEnd(203);
  l2.toEnd(1111);
  sortList(l2);

  mergeList(l1, l2, r);
  r.print();
}